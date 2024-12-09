# include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
struct node * create_node(){
    return (struct node *) malloc(sizeof(struct node));
}
 void add_beg(){
    int info;
    struct node *temp = create_node();
    printf("\nEnter data to the new node : ");
    scanf("%d",&info);
    temp->data=info;
    temp->next=NULL;
    if(start!=NULL)
     temp->next=start;
    start=temp;
    printf("Node added at the begining\n");
}
void add_last(int info){
    struct node *newnode=create_node();
    newnode->data=info;
    newnode->next=NULL;
    if (start==NULL)
    start=newnode;
    else{
        struct node *temp = start;
        while(temp->next!=NULL)
           temp=temp->next;
           temp->next=newnode;
    }
    printf("Nodes aaded at last\n");
}
void show(){
    if(start==NULL)
    printf("List is Empty");
    else{
        struct node *temp=start;
        printf("Nodes are \n");
        while(temp!=NULL){
            printf("%d | %x\n",temp->data,temp->next);
            temp=temp->next;
        }
    }
}
int main(){
    start=NULL;
    show();
    for(int i=0;i<10;i++){
        add_last(i*200);
        add_beg(i*10);
        show();
    }
}
