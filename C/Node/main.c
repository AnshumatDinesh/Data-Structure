#include "node.c"
int main(){
    Node head;
    head.x=5;
    head.pntr_to_next_node=NULL;
    make_node(7,&head);
    make_node(8,&head);
    make_node(3,&head);
    make_node(4,&head);
    print(&head);

}