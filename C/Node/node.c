#include<stdio.h>
typedef struct node
{
    int value;
    struct node * pntr_to_next_node;
}Node;
Node make_node(int n,Node * pntr_next){
    Node new={n,pntr_next};
    return new;
}
int get_value(Node n){
    return n.value;
}
Node* get_next(Node n){
    return n.pntr_to_next_node;
}
void set_value(Node *n,int new_value){
    (*n).value=new_value;
}
void set_value(Node *n,int new_value){
    (*n->pntr_to_next_node).value=new_value;
}
