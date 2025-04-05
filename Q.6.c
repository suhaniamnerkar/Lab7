#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
    char arr[100];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char value) {
    stack->arr[++stack->top] = value;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int isPalindrome(char* str) {
    int len = strlen(str);
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&stack)) {
            return 0;  
        }
    }

    return 1; 
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
