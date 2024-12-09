#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void addbeg(struct node **start, int data)
{
    struct node *temp = create_node(data);
    if (*start != NULL)
    {
        temp->next = *start;
    }
    *start = temp;
}
void show(struct node *start)
{
    while (start != NULL)
    {
        printf("%d\n", start->data);
        start = start->next;
    }
}
void addlast(struct node **start, int data)
{
    struct node *temp = create_node(data);
    if (*start == NULL){
        *start = temp;
        return;
    }
    struct node *p = *start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->next = NULL;
}
void delbeg(struct node **start){
    if(*start == NULL)
    return;
    struct node* temp= *start;
    *start=(*start)->next;
    free(temp);
}
void dellast(struct node **start){
    if(*start == NULL)
      return;
    struct node *p= *start;
    struct node *prev= *start;
    while(p->next!=NULL){
        prev=p;
        p=p->next;
    }
    prev->next=NULL;
    free(p);
}