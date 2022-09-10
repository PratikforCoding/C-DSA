#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node node;
node *REAR = NULL;
node *FRONT = NULL;
node *HEAD;


void insert(int data) {
    node *p = (node *)malloc(sizeof(node));
    p->info = data;
    p->next = NULL;
    if (REAR == NULL) {
        HEAD = p;
        REAR = p;
    } else {
        REAR->next = p;
        REAR = REAR->next;
    }
}

void delete() {
    node *p;
    if (REAR == NULL ) {
        printf("\nQueue underflow...");
    } else {

        FRONT = HEAD;
        p = FRONT;
        printf("\nThe deleted element is: %d" ,p->info);
        HEAD = HEAD->next;
        FRONT = FRONT->next;
        free(p);
    }
}

void display() {
    node *temp;
    if (HEAD == NULL) {
        printf("Queue underflow...");
    } else {
        temp = HEAD;
        printf("\nThe queue is: ");
        while (temp !=  NULL) 
        {
            printf("%d  " ,temp->info);
            temp = temp->next;
        }
        
    }
}

int main() {
    int option;
    char ch;
    int value;
    do
    {
        
        printf("\nEnter 1 to insert.\nEnter 2 to delete.\nEnter 3 to display.");
        printf("\nEnter your choice--> ");
        scanf("%d" ,&option);
        switch (option)
        {
        case 1: 
            printf("\nEnter the value to insert: ");
            scanf("%d" ,&value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
           printf("\nEnter a corect option.");
        }
        printf("\nPress y or Y to contionue--> ");
        fflush(stdin);
        scanf("%c" ,&ch);
        
    } while (ch == 'y' || ch =='Y');
    printf("\nInvalid input.");
    return 0;
}