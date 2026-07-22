#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void Insert(struct Node** head,int element,int pos){
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=element;
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
void Deletion(struct Node** head,int pos){
    struct Node* temp1=*head;
    if(pos==1){
        *head=temp1->next;
        free(temp1);
        return;
    }
    else{
        for(int i=0;i<pos-2;i++){
            temp1=temp1->next;
        }
        struct Node* temp2=temp1->next;
        temp1->next=temp2->next;
        
    }
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
    Insert(&pointerToHead,1,1);
    Insert(&pointerToHead,2,2);
    Insert(&pointerToHead,3,3);
    Print(pointerToHead);
    Deletion(&pointerToHead,1);
    Print(pointerToHead);
    return 0;
}