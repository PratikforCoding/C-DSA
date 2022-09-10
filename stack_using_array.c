#include<stdio.h>
#define SIZE 10

int stack[SIZE];
int TOP = -1;
void PUSH(int item) {
    if (TOP >= SIZE - 1) {
        printf("\nStack overflow...");
    } else {
        TOP = TOP + 1;
        stack[TOP] = item;
    }
}

void POP() {
    int item;
    if (TOP < 0) {
        printf("\nStack underflow\n");
    } else {
        item = stack[TOP];
        stack[TOP] = 0;
        printf("\nPopped element is: %d" ,item);
        TOP = TOP - 1;
    }
}

void display() {

    printf("\nThe stack is : ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ",stack[i]);
    }
    
}

int main() {
    int option, key;
    char ch;
    
    do
    {
        printf("\nPress 1 to PUSH an element into stack\nPress 2 to POP an element from the stack\nPress 3 to display\nPress 4 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d" ,&option);
        switch (option)
        {
        case 1:
        printf("\nEnter the element you wanna push: ");
        scanf("%d" ,&key);
        PUSH(key);
        display();
        break;

        case 2:
        POP();
        printf("\n");
        display();
        break;
        
        case 3:
        display();
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