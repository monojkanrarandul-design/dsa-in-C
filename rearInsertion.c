#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void InsertB(struct Node** head,struct Node** tail,int element){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=element;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;
        *tail=temp;
        return;
    }
    (*tail)->next=temp;
    (*tail)=temp;
}
void Print(struct Node* matha){
    struct Node* mod=matha;
    while(mod!=NULL){
        printf("%d, ",mod->data);
        mod=mod->next;
    }
    printf("\n");
}
int main(){
    struct Node* pointerToHead=NULL;
    struct Node* pointerToTail=NULL;
    int size,member;
    printf("Enter size: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter element: ");
        scanf("%d",&member);
        InsertB(&pointerToHead,&pointerToTail,member);
    }
    Print(pointerToHead);
    return 0;
}