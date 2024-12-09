#include"linkedlist.h"
int main(){
    struct node * start = NULL;
    addlast(&start,10);
    addlast(&start,20);
    dellast(&start);
    show(start);
}