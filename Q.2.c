#include<stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node*next;
};


struct node*create_node(int data){
    struct node*cnode=(struct node*)malloc(sizeof(cnode));
    cnode->a=data;
    cnode->next=NULL;
    return cnode;
}

struct node*input(int data,struct node*head){
    struct node*nnode=create_node(data);
    if(head==NULL){
        head=nnode;
        return head;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nnode;
    return head;
}

void display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->a);
        ptr=ptr->next;
    }
}

struct node* pop(struct node*head){
    struct node*top=head,*prev=NULL;
    while(top->next!=NULL){
        prev=top;
        top=top->next;
    }
    printf("The element that is popped is %d",top->a);
    struct node*temp=top;
    prev->next=NULL;
    free(temp);
    return head;
}

struct node*push(struct node*head,int data){
    struct node*nnode=create_node(data);
    struct node*top=head;
    while(top->next!=NULL){
        top=top->next;
    }
    top->next=nnode;
    return head;
}

int main(){
    int n;
    struct node*nnode,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }
    head=pop(head);
    printf("Elements after popping are\n");
    display(head);

    int data1;
    printf("Enter the element to be pushed:");
    scanf("%d",&data1);
    head=push(head,data1);
    printf("Elements after pushing are:\n");
    display(head);

    return 0;
}
