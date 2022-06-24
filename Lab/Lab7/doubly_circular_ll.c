#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int value;
  struct node *next;
  struct node *prev;
}circular_ll;
void initialize(circular_ll **head,int init_val){
    circular_ll *new_node;
    new_node=(circular_ll*)malloc(sizeof(circular_ll));
    *(head)=new_node;
    new_node->value=init_val;
    new_node->next=*head;
    new_node->prev=*head;
}
void append(circular_ll **head,int val){
    circular_ll *new_node;
    new_node=(circular_ll*)malloc(sizeof(circular_ll));
    new_node->value=val;
    if(head==NULL){
        *(head)=new_node;
        new_node->next=(*head);
        new_node->prev=(*head);
        return;
    }
    circular_ll *nxt=(*head);
    do{
        printf("%d<-->",nxt->value);
        nxt=nxt->next;
    }
    while(nxt->next!=(*head));
    circular_ll *temp;
    temp=nxt->next;
    nxt->next=new_node;
    new_node->next=temp;
    new_node->prev=nxt;
    new_node->next->prev=new_node;

}
void pushf(circular_ll **head,int val){
    circular_ll *new_node;
    new_node=(circular_ll*)malloc(sizeof(circular_ll));
    new_node->value=val;
    if(head==NULL){
        *(head)=new_node;
        new_node->next=(*head);
        new_node->prev=(*head);
        return;
    }
    new_node->next=*head;
    circular_ll *temp;
    temp=(*head)->prev;
    (*head)->prev=new_node;
    new_node->prev=temp;
    temp->next=new_node;
    (*head)=new_node;
}
void print(circular_ll *head){
    if(head==NULL){
        return;
    }
    circular_ll *nxt=head;
    do{
        printf("%d<-->",nxt->value);
        nxt=nxt->next;
    }
    while(nxt!=head);
    printf("HEAD\n");
}
int main(){
    int runner=1,menu;
    circular_ll *c_ll;
    while(runner){
        printf("0.Exit\n");
        printf("1.Create a link list\n");
        printf("2.Insert a node at begining\n");
        printf("3.Insert a node at a given index\n");
        printf("4.Insert a node at end\n");
        printf("5.Delete a node at begining\n");
        printf("6.Delete a node at a given index\n");
        printf("7.Delete a node at a end\n");
        printf("8.Display the list\n");
        printf("9.Count of node\n");
        printf("10.Reverse a list\n");
        printf("11.Sort a list\n");
        scanf("%d",&menu);
        int num,ind;
        switch(menu){
            case 0:
                runner=0;
                break;
            case 1:
                printf("Enter the value of first node");
                scanf("%d",&num);
                initialize(&c_ll,num);
                break;
            case 2:
                printf("Enter the Value");
                scanf("%d",&num);
                pushf(&c_ll,num);
                break;
            case 4:
                printf("Enter the Value");
                scanf("%d",&num);
                append(&c_ll,num);
                break;
            case 8:
                print(c_ll);
                break;
        }
    }
}