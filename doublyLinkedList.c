#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
void Insert(struct Node** head,int element){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=element;
    temp->next=NULL;
    temp->prev=NULL;
    if(*head==NULL){
        *head=temp;
        return;
    }
    (*head)->prev=temp;
    temp->next=*head;
    (*head)=temp;
}
void Print(struct Node* head){
    if(head==NULL){
        printf("\n");
        return;
    }
    printf("%d, ",head->data);
    Print(head->next);
}
void Reverse(struct Node** head,struct Node* p){
    if(p==NULL){
        return;
    }
    if(p->next==NULL){
        *head=p;
        return;
    }
    Reverse(head,p->next);
    struct Node* q=p->next;
    q->next=p;
    p->next=NULL;
}
int main(){
    struct Node* head=NULL;
    int size,el;
    printf("Enter size: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter element: ");
        scanf("%d",&el);
        Insert(&head,el);
    }
    //Insert function works here.
    Print(head);
    Reverse(&head,head);
    //Reverse function works here
    Print(head);
    return 0;
}