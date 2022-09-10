#include<stdio.h>
#define MAX 10
int queue[MAX];
int rear = -1;
int front = -1;

void insert(int value) {
    if(rear >= MAX) {
        printf("\nQueue OVERFLOW.");
    } else {
        rear += 1;
        queue[rear] = value;
    }
}
void delete() {
    if(rear < 0) {
        printf("\nQueue UNDERFLOW");
    } else {
        int num;
        front += 1;
        num = queue[front];
        queue[front] = 0;
        if (rear == front) {
            rear = front = -1;
        }
    }
}
void display() {
    int i;
    for(i = front+1; i <= rear; i++) {
        printf("\nqueue[%d]:%d    " ,i ,queue[i]);
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

