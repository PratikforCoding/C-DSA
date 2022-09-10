#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top = -1;
int result;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return (stack[top--]);
}
int isOperator(char c) {
    if (c == '^' || c == '/' || c == '*' || c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
int priority(char c) {
    if (c == '^') {
        return 3;
    } else if(c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}
void convert(char infix[]) {
    int i = 0,j = 0;
    char item;
    while(infix[i] != '\0') {
        if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while((item = pop()) != '(') {
                postfix[j++] = item;
            }
        } else if(isOperator(infix[i])) {
            while(top >= 0 && priority(stack[top]) >= priority(infix[i]) ) {
                item = pop();
                postfix[j++] = item;
            }
            push(infix[i]);
        } else {
            postfix[j++] = infix[i];
        }
        i++;
    }
    while(top >= 0) {
        item = pop();
        postfix[j++] = item;
    }
    postfix[j] = '\0';
}

int evaluation() {
    int i, opnd1, opnd2, res;
    char oprt;
    while (postfix[i] != '\0')
    {
        if(isOperator(postfix[i])) {
            opnd2 = pop() - '0';
            opnd1 = pop() - '0';
            oprt = postfix[i];
            switch (oprt)
            {
            case '^':
            res = pow(opnd1, opnd2);
            break;
            case '/':
            res = opnd1 / opnd2;
            break;
            case '*':
            res = opnd1 *opnd2;
            break;
            case '+':
            res = opnd1 + opnd2;
            break;
            case '-':
            res = opnd1 - opnd2;
            break;
            default:
            break;
            }
            push((char)res);
        } else {
            
            push(postfix[i]);
        } 
        i++;
    }
    return (pop() - '0');
    
}

void display() {
    int i = 0;
    printf("\nThe postfix expression is: ");
    while(postfix[i] != '\0') {
        printf("%c" ,postfix[i]);
        i++;
    }
}

int main() {
    
    printf("\nEnter the infix expression: ");
    scanf("%s" ,infix);
    convert(infix);
    display();
    return 0;
}
