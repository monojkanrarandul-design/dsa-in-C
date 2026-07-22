#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Insert(struct Node **head,int element){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=element;
    temp->next=*head;
    *head=temp;

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
    int size,el;
    printf("Enter size: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter element: ");
        scanf("%d",&el);
        Insert(&pointerToHead,el);
    }
    Print(pointerToHead);
    return 0;
}