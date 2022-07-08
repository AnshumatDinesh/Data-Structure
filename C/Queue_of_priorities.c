#include<stdio.h>
#include<stdlib.h>
struct queue{
    char *name_of_task;
    struct queue* next;
};
void push(struct queue **head, char*name){
    if((*head)==NULL){
        (*head)=(struct queue*)malloc(sizeof(struct queue));
        char *name_cpy = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(name_cpy, name);
        (*head)->name_of_task=name_cpy;
        (*head)->next=NULL;
        return;  
    }
    struct queue *new_node,*trav=(*head);
    new_node=(struct queue*)malloc(sizeof(struct queue));
    char *name_cpy = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(name_cpy, name);
    new_node->name_of_task=name_cpy;
    new_node->next=NULL;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=new_node;
}
void pop(struct queue **head){
    if((*head)==NULL){
        return;  
    }
    struct queue *output;
    output=(*head);
    (*head)=(*head)->next;
    // free(output);
}
char* front(struct queue **head){
    if((*head)==NULL){
        return NULL;  
    }
    return (*head)->name_of_task;
}
int isempty(struct queue **head){
    if((*head)==NULL){
        return 1;  
    }
    return 0;
}
void print(struct queue *head)
{
  struct queue *pntr_nxt = head;
  while (pntr_nxt != NULL)
  {
    printf("%s-->", (*pntr_nxt).name_of_task);
    pntr_nxt = (*pntr_nxt).next;
  }
  printf("NULL\n");
}
int main(){
    int runner=1,menu;
    struct queue * q1,q2,q3,q4;
    while(runner){
        printf("1.Create a task\n");
        printf("2.Remove a task\n");
        printf("3.Display tasks of same priority\n");
        printf("4.Exit\n");
        scanf("%d",&menu);
        int pri;
        switch(menu){
            case 1:
                char* name;
                printf("ENTER THE NAME OF THE TASK\n");
                scanf("%s",name);
                printf("ENTER THE PRIORITY OF THE TASK\n");
                scanf("%d",&pri);
                switch(pri){
                    case 1:
                        push(&q1,name);
                        break;
                    case 2:
                        push(&q2,name);
                        break;
                    case 3:
                        push(&q3,name);
                        break;
                    case 4:
                        push(&q4,name);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("ENTER THE PRIORITY OF THE TASK\n");
                scanf("%d",&pri);
                switch(pri){
                    case 1:
                        pop(&q1);
                        break;
                    case 2:
                        pop(&q2);
                        break;
                    case 3:
                        pop(&q3);
                        break;
                    case 4:
                        pop(&q4);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                printf("ENTER THE PRIORITY OF THE TASK\n");
                scanf("%d",&pri);
                switch(pri){
                    case 1:
                        print(&q1);
                        break;
                    case 2:
                        print(&q2);
                        break;
                    case 3:
                        print(&q3);
                        break;
                    case 4:
                        print(&q4);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                runner=0;
                break;
            default:
                break;
        }
    }
}