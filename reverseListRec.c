#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void InsertN(struct Node** head,int el,int pos){
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=el;
    temp1->next=NULL;
    if(pos==1){
        temp1->next=*head;
        *head=temp1;
        return;
    }
    struct Node* temp2=*head;
    for(int i=0;i<pos-2;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void PrintRec(struct Node* p){
    if(p==NULL){
        printf("\n");
        return;
    }
    printf("%d, ",p->data);
    PrintRec(p->next);
}
void ReverseRec(struct Node** head,struct Node* p){
    if(p==NULL){
        
        return;
    }
    if(p->next==NULL){
        *head=p;
        return;
    }
    ReverseRec(head,p->next);
    struct Node* q=p->next;
    q->next=p;
    p->next=NULL;
}
int main(){
    struct Node* head=NULL;
    
    InsertN(&head,1,1);
    InsertN(&head,2,2);
    InsertN(&head,0,1);
    InsertN(&head,3,4);
    PrintRec(head);
    ReverseRec(&head,head);
    PrintRec(head);
    return 0;
}
