#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node node;

node *PUSH(node *top, int item) {
    node *p = (node *)malloc(sizeof(node));
    p->info = item;
    p->next = NULL;
    if (top == NULL) {
        top = p;
    } else {
        p->next = top;
        top = p;
    }
    return top;
    
}

node *POP(node *top) {
    int item;
    node *p;
    if(top == NULL) {
        printf("\nStack is empty...");
    } else {
        p = top;
        item  = top->info;
        printf("\nThe popped item is %d" ,item);
        top = top->next;
        free(p);
    }
    return top;
}

void display(node *top) {
    node *temp;
    if (top == NULL) {
        printf("\nStack is empty...");
    } else {
        temp = top;
        printf("\nThe stack is: ");
        while(temp != NULL) {
            printf("%d  ",temp->info );
            temp = temp->next;
        }
    }
}

int main() {
    int option, key;
    char ch;
    node *TOP = NULL;

    do
    {
        printf("\nPress 1 to PUSH an element into stack\nPress 2 to POP an element from the stack\nPress 3 to display the stack\nPress 4 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d" ,&option);
        switch (option)
        {
        case 1:
        printf("\nEnter the element you wanna push: ");
        scanf("%d" ,&key);
        TOP = PUSH(TOP,key);
        display(TOP);
        break;

        case 2:
        TOP = POP(TOP);
        display(TOP);
        break;
        
        case 3:
        display(TOP);
        break;

        case 4:
        break;
        
        default:
        printf("\nEnter a valid choice...");
        }

        printf("\nDo you wanna continue y/Y: ");
        fflush(stdin);
        scanf("%c" ,&ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\nProcedure ended because of wrong input...");
    return 0;
    
}