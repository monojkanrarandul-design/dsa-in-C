#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void Insert(struct Node** head,int element,int pos){
    struct Node* temp_1=(struct Node*)malloc(sizeof(struct Node));
    temp_1->data=element;
    temp_1->next=NULL;
    if(pos==1){
        temp_1->next=*head;
        *head=temp_1;
        return;
    }
    struct Node* temp_2=*head;
    for(int i=0;i<pos-2;i++){
        
        temp_2=temp_2->next;
    }
    
    
    temp_1->next=temp_2->next;
    temp_2->next=temp_1;
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
    Insert(&pointerToHead,1,1);
    Insert(&pointerToHead,2,2);
    Insert(&pointerToHead,3,3);
    Print(pointerToHead);
    return 0;
}