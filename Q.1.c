#include<stdio.h>
#include<stdlib.h>

void pop(int *top,int arr[]){
    if(*top==-1){
        printf("The stack is empty");
    }
    else{
        int popped=arr[*top];
        printf("The element at top was %d\n",popped);
        (*top)--;
    }
    int popup=arr[*top];
    printf("The element at top now is %d\n",popup);
}

void push(int data,int arr[],int n,int *top){
    if(*top==n-1){
        printf("Stack is full");
    }
    else{
        (*top)++;
        arr[*top]=data;
        int topnew=arr[*top];
        printf("The top is now at %d\n",topnew);
    }
    printf("Current stack elements:\n");
    for(int i=0;i<=*top;i++){
        printf("%d\n",arr[i]);
    }

}

int main(){
    int n;
    printf("Enter the number of elements you want to enter:");
    scanf("%d",&n);
    int arr[n];
    int top=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        top++;
    }
    pop(&top,arr);

    int data;
    printf("Enter the element you want to push into the stack");
    scanf("%d",data);
    push(data,arr,n,&top);

    
    return 0;
}

