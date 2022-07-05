#include"stack.c"
struct queue{
    Stack stck;
};
void init_queue(Stack *pntr_queue){
    initialize(pntr_queue);
}
void enqueue(Stack *pntr_queue,int val){
    push(pntr_queue,val);
}
int dequeue(Stack *pntr_queue){
    if(isempty(pntr_queue)){
        return -1;
    }
    if(pntr_queue->height==1){
        return pop(pntr_queue);
    }
    Stack temp_stck;
    initialize(&temp_stck);
    while(pntr_queue->height>1){
        push(&temp_stck,pop(pntr_queue));
    }
    int output=pop(pntr_queue);
    while(!isempty(&temp_stck)){
        push(pntr_queue,pop(&temp_stck));
    }
    delete_stack(&temp_stck);
    return output;
}
int main(){
    Stack q1;
    int menu,runner=1;
    while(runner){
        printf("1.Create a Queue\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Display the queue\n");
        printf("5.Exit\n");
        scanf("%d",&menu);
        int num;
        switch(menu){
            case 1:
                init_queue(&q1);
                break;
            case 2:
                printf("Enter the number:");
                scanf("%d",&num);
                enqueue(&q1,num);
                break;
            case 3:
                dequeue(&q1);
                break;
            case 4:
                print(&q1);
                break;
            case 5:
                runner=0;
                break;
            default:
                runner=0;
                break;
        }
    }
}