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
void Reverse(struct Node** head){
    struct Node *prev,*current,*later;
    current=*head;
    prev=NULL;
    while(current!=NULL){
        later=current->next;
        current->next=prev;
        prev=current;
        current=later;
    }
    *head=prev;
}
void Print(struct Node* head){
    struct Node* mod=head;
    while(mod!=NULL){
        printf("%d, ",mod->data);
        mod=mod->next;
    }
    printf("\n");
}
int main(){
    struct Node* pointerToHead=NULL;
    InsertN(&pointerToHead,1,1);
    InsertN(&pointerToHead,2,2);
    InsertN(&pointerToHead,3,3);
    Print(pointerToHead);
    Reverse(&pointerToHead);
    Print(pointerToHead);
    return 0;
}