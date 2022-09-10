#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node node;

node *insert_node(node *head , int data){
    node *temp;
    node *newp;
    newp = (node *)malloc(sizeof(node));
    newp->info = data;
    newp->next = NULL;
    if (head == NULL) {
        head = newp;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newp;
    }
    return head;
}
node *insert_beginning( node *head, int data) {
    node *newp = (node *)malloc(sizeof(node));
    newp->info = data;
    newp->next = NULL;
    if(head == NULL) {
        head = p;
    } else {
        newp->next = head;
        head = newp;
    }
    return head;
}
node *insert_after_node(node *head, int key, int data) {
    node *temp;
    node *prev;
    node *newp = (node *)malloc(sizeof(node));
    newp->info = data;
    newp->next = NULL;
    if(head == NULL) {
        head = newp;
    } else {
        temp = head;
        while(temp != NULL && temp->info != key) {
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL) {
            newp->next = temp->next;
            temp->next = newp;
        } else {
            prev->next = newp;
        }
    }
    return head;
}
node *insert_before_node(node *head, int key, int data) {
    node *temp;
    node *prev;
    node *newp = (node *)malloc(sizeof(node));
    newp->info = data;
    newp->next = NULL;
    if(head == NULL) {
        head = newp;
    } else {
        temp = head;
        while(temp != NULL && temp->info != key) {
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL) {
            newp->next = temp;
            prev->next = newp;
        } else {
            prev->next = newp;
        }
    }
    return head;
}

node *insert_at(node *head, int pos, int data) {
    node *temp;
    node *newp = (node *)malloc(sizeof(node));
    newp->info = data;
    newp->next = NULL;
    int counter;
    if (head == NULL) {
        head = newp;
    } else {
        temp  = head;
        counter = 1;
        while(counter < pos-1 && temp != NULL) {
            temp = temp->next;
            counter++;
        }
        if (temp != NULL) {
            newp->next = temp->next;
            temp->next = newp;
        } else {
            printf("\nInvalid position given...");
        }
    }
    return head;
}
node *delete_first_node(node *head) {
    node *temp;
    if(head == NULL) {
        printf("\nEmpty List.\n");
    } else {
        temp = head;
        head = temp->next;
        free(temp);
    }
    return head;
}
node *delete_last_node(node *head) {
    node *temp;
    node *prev;
    if(head == NULL) {
        printf("\nEmpty List.\n");
    } else {
        temp = head;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return head;
}
node *delete_node(node *head, int key) {
    node *temp;
    node *prev;
    if(head == NULL) {
        printf("\nEmpty List.\n");
    } else {
        temp = head;
        while(temp != NULL && temp->info != key) {
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL) {
            prev->next=temp->next;
            free(temp);
        } else {
            printf("\nNo such node found.\n");
        }
    }
    return head;
}

node *delete_at(node *head, int pos) {
    node *p, *q;
    int counter;
    if (head == NULL) {
        printf("\nLinked list is empty...");
    } else {
        q = head;
        counter = 1;
        while(counter < pos && q != NULL) {
            p = q;
            q = q->next;
            counter++;
        }
        if (q != NULL) {
            p->next = q->next;
            free(q);
        } else {
            printf("\nInvalid position...");
        }
    }
    return head;
}

void search(node *head, int data) {
    node *temp;
    int counter = 1;
    if (head == NULL) {
        printf("\nLinked list is empty...");
    } else {
        temp = head;
        while(temp->info != data && temp != NULL) {
            temp = temp->next;
            counter++;
        }
        if (temp != NULL) {
            printf("Position of the element %d is %d. ", data, counter);
        }

    }
}

void forward_trvs(node *head) {
    node *temp;
    if (head == NULL) {
        printf("\nEmpty List.\n");
    } else {
        temp = head;
        while(temp != NULL) {
            printf("%d  " ,temp->info);
            temp = temp->next;
        }
    }
}
node *backward_trvs(node *head) {
    node *nxt;
    node *prev = head;
    node *p = prev->next;
    prev->next = NULL;
    while(p != NULL) {
        nxt = p->next;
        p->next = prev;
        prev = p;
        p = nxt;
    }
    head = prev;
    return head;
}
void display(node *head) {
    node *temp = head;
    if(head == NULL) {
        printf("\nEmpty List.\n");
    } else {
         while(temp != NULL) {
            printf("%d  " ,temp->info);
            temp = temp->next;
        }
    }
}
node *concat_list(node *ptr1, node *ptr2) {
    node *p = ptr1;
    node *q = ptr2;
    node *result = p;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = q;
    return result;
}
node *create(node *head) {
    int n, i, data;
    printf("\nHow many nodes you wanna enter: ");
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        printf("\nenter the data: ");
        scanf("%d" ,&data);
        head = insert_node(head , data);
    }
    return head;
}
int main () {
    
    int num, key, del, option, option2, data;
    char ch;
    node *list1 = NULL;
    list1 = create(list1);
    node *list2 = NULL;
    list2 = create(list2);
    node *result = NULL;
    display(list1);
    printf("\n");
    display(list2);
    do
    {
       printf("\nPress 1 for insertion\nPress 2 for deletion\nPress 3 for traversal\nPress 4 for display\nPress 5 for concatenation\nPress 6 to search for an element\nPress 7 to exit the process\n");
       printf("\nEnter your choice: ");
       scanf("%d" ,&option);
        switch(option) {
            case 1:
            printf("\nPress 1 to insert at beginning\nPress 2 to insert at end\nPress 3 to insert after a node\nPress 4 to insert before a node\nPress 5 to insertb at a position\nPress 6 to exit\nEnter your choice: ");
            scanf("%d" ,&option2);
            switch(option2) {
                case 1:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                list1 = insert_beginning(list1, data);
                display(list1);
                break;
                case 2:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                list1 = insert_node(list1 , data);
                display(list1);
                break;
                case 3:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                printf("\nEnter the node info after which you want to insert: ");
                scanf("%d" ,&key);
                list1 = insert_after_node(list1, key, data);
                display(list1);
                break;
                case 4:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                printf("\nEnter the node info before which you want to insert: ");
                scanf("%d" ,&key);
                list1 = insert_before_node(list1 , key, data);
                display(list1);
                break;
                case 5:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                printf("\nEnter the position: ");
                scanf("%d" ,&key);
                list1 = insert_at(list1, key, data);
                display(list1);
                break;
                case 6:
                break;
                default :
                printf("\nEnter a correct choice.\n");
                break;
            }
            break;
            case 2:
            printf("\nPress 1 to delete first node\nPress 2 to delete last node\nPress 3 to delete a particular node\nPress 4 to delete the position\nPress 5 to exit\nEnter your choice: ");
            scanf("%d" ,&option2);
            switch(option2) {
                case 1:
                list1 = delete_first_node(list1);
                display(list1);
                break;
                case 2:
                list1 = delete_last_node(list1);
                display(list1);
                break;
                case 3:
                printf("\nEnter the info of the node you want to delete: ");
                scanf("%d" ,&del);
                list1 = delete_node(list1, del);
                display(list1);
                break;
                case 4:
                printf("\nEnter the position you wanna delete: ");
                scanf("%d" ,&del);
                list1 = delete_at(list1, del);
                display(list1);
                break;
                case 5:
                break;
                default: 
                printf("\nEnter a correct choice.\n");
                break;
            }
            break;
            case 3:
            printf("\nPress 1 for forward traversal\nPress 2 for backward traversal\nPress 3 to exit\nEnter your choice: ");
            scanf("%d" ,&option2);
            switch(option2) {
                case 1:
                forward_trvs(list1);
                break;
                case 2:
                list1 = backward_trvs(list1);
                display(list1);
                break;
                case 3:
                break;
                default:
                printf("\nEnter correct choice.\n");
                break;
            }
            break;
            case 4:
            display(list1);
            break;
            case 5:
            result = concat_list(list1, list2);
            display(result);
            break;
            case 6:
            printf("\nEnter the element to search: ");
            scanf("%d" ,&key);
            search(list1, key);
            case 7:
            break;
            default:
            printf("\nEnter a valid choice./n");
            break;
        }
        printf("\nPress y or Y to continue: ");
        fflush(stdin);
        scanf("%c" ,&ch);
    } while (ch == 'y' || ch == 'Y');
    
    printf("\nEnd of the procedure becuase of invlaid input.\n");
    return 0;
}
