#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  // Maximum size of the stack

struct Stack {
    int arr[MAX];
    int top;
};


void initStack(struct Stack* stack) {
    stack->top = -1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


int operate(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}


int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        
        if (isdigit(token)) {
            push(&stack, token - '0');  
        }
        
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = operate(operand1, operand2, token);
            push(&stack, result);
        }
    }

    return pop(&stack);  

