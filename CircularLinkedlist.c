#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node node;
node *insert_beg(node *head, int data){
    node *temp;
    node *p = (node *)malloc(sizeof(node));
    p->info = data;
    p->next = NULL;
    if(head == NULL) {
        head = p;
        p->next = head;
    } else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
        head = p;

    }
    return head;
}

node *insert_node(node *head, int data) {
    node *temp;
    node *p = (node *)malloc(sizeof(node));
    p->info = data;
    p->next = NULL;
    if(head ==  NULL) {
        head = p;
        p->next = head;
    } else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
        
    }
    
    return head;
}

node *insert_at(node *head, int pos, int data) {
    node *temp;
    node *p = (node *)malloc(sizeof(node));
    p->info = data;
    p->next = NULL;
    int counter;
    if (head == NULL) {
        head = p;
        p->next = head;
    } else {
        temp  = head;
        counter = 1;
        while(counter < pos-1 && temp->next != head) {
            temp = temp->next;
            counter++;
        }
        if (temp->next != head) {
            p->next = temp->next;
            temp->next = p;
        } else {
            printf("\nInvalid position given...");
        }
    }
    return head;
}

node *delete_first(node *head) {
    node *p;
    node *q;
    if (head == NULL) {
        printf("\nNo such element to delete.");
    } else {
        p = head;
        head = p->next;
        q = head;
        while(q->next != p) {
            q = q->next;
        }
        q->next = p->next;
        free(p);
    }
    return head;
}

node *delete_last(node *head) {
    node *q;
    node *r;
    if (head == NULL) {
        printf("\nNo such element to delete.");
    } else {
        q = head;
        while(q->next != head) {
            r = q;
            q = q->next;
        }
        r->next = q->next;
        free(q);
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
        while(counter < pos && q->next != head) {
            p = q;
            q = q->next;
            counter++;
        }
        if (q->next != head) {
            p->next = q->next;
            free(q);
        } else {
            printf("\nInvalid position...");
        }
    }
    return head;
}

node *reverse(node *head) {
    if (head == NULL) {
        printf("\nNo element to display.");
    } else {
        
        node *prev = head;
        node *temp = prev->next;
        node *nxt;
        node *temp2 = head;
        while(temp2->next != head) {
            temp2 = temp2->next;
        }
        prev->next = temp2;
        while(temp->next != head) {
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        temp->next = prev;
        head = temp;
        
    }
    return head;
    
}

node *create(node *head) {
    int i, n, data;
    printf("\nHow many nodes you wanna enter: ");
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        printf("\nEnter the data: ");
        scanf("%d" ,&data);
        head = insert_node(head, data);
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
        while(temp->info != data && temp->next != head) {
            temp = temp->next;
            counter++;
        }
        if (temp->next != head) {
            printf("Position of the element %d is %d. ", data, counter);
        } else {
            if (temp->info == data) {
                printf("Position of the element %d is %d. ", data, counter);
            }
        }

    }
}

void display(node *head) {
    node *temp;
    if (head == NULL) {
        printf("\nNo Item.");
    } else {
        temp = head;
        while(temp->next != head) {
            printf("%d  " ,temp->info);
            temp = temp->next;
        }
        printf("%d" ,temp->info);
    }
}

int main () {
    
    int num, key, del, option, option2, data;
    char ch;
    node *list1 = NULL;
    list1 = create(list1);
    node *result = NULL;
    display(list1);
    printf("\n");
    
    do
    {
       printf("\nPress 1 for insertion\nPress 2 for deletion\nPress 3 to search for an element\nPress 4 to reverse the list\nPress 5 to exit the process\n");
       printf("\nEnter your choice: ");
       scanf("%d" ,&option);
        switch(option) {
            case 1:
            printf("\nPress 1 to insert at beginning\nPress 2 to insert at end\nPress 3 to insert at a position\nPress 4 to exit\nEnter your choice: ");
            scanf("%d" ,&option2);
            switch(option2) {
                case 1:
                printf("\nEnter the data of new node: ");
                scanf("%d" ,&data);
                list1 = insert_beg(list1, data);
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
                printf("\nEnter the position: ");
                scanf("%d" ,&key);
                list1 = insert_at(list1, key, data);
                display(list1);
                break;
                case 4:
                break;
                default :
                printf("\nEnter a correct choice.\n");
                break;
            }
            break;
            case 2:
            printf("\nPress 1 to delete first node\nPress 2 to delete last node\nPress 3 to delete the position\nPress 4 to exit\nEnter your choice: ");
            scanf("%d" ,&option2);
            switch(option2) {
                case 1:
                list1 = delete_first(list1);
                display(list1);
                break;
                case 2:
                list1 = delete_last(list1);
                display(list1);
                break;
                case 3:
                printf("\nEnter the position you wanna delete: ");
                scanf("%d" ,&del);
                list1 = delete_at(list1, del);
                display(list1);
                break;
                case 4:
                break;
                default: 
                printf("\nEnter a correct choice.\n");
                break;
            }
            break;
            case 3:
            printf("\nEnter the element to search: ");
            scanf("%d" ,&key);
            search(list1, key);
            break;
            case 4:
            list1 = reverse(list1);
            display(list1);
            break;
            case 5:
            break;
            default:
            printf("\nEnter a valid choice./n");
            break;
        }
        printf("\nPress y or Y to continue: ");
        fflush(stdin);
        scanf("%c" ,&ch);
    } while (ch == 'y' || ch == 'Y');
    
    printf("\nEnd of the procedure because of invalid input.\n");
    return 0;
}