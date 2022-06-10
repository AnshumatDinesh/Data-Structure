#include<stdio.h>
#define OR ||
#define AND &&
#define MAX 10
typedef struct cq{
    int a[MAX];
    int front;
    int rear;
}circular_queue;
int isfull(circular_queue cq){
    if((cq.front==cq.rear+1 )OR(cq.front==0 AND cq.rear==MAX-1)){
        return 1;
    }
    return 0;
}
int isempty(circular_queue cq){
    if(cq.front==-1){
        return 1;
    }
    return 0;
}
void initialize(circular_queue *pntr_to_cq){
    pntr_to_cq->front=-1;
    pntr_to_cq->rear=0;
}
void inqueue(circular_queue *pntr_to_cq,int val){
    if(isfull(*pntr_to_cq)){
        printf("OVERFLOW\n");
        return;
    }
    if(pntr_to_cq->front==-1){
        pntr_to_cq->front=0;
    }
    pntr_to_cq->a[pntr_to_cq->rear]=val;
    pntr_to_cq->rear=(pntr_to_cq->rear+1)%MAX;
}
int dequeue(circular_queue *pntr_to_cq){
    if(isempty(*pntr_to_cq)){
        printf("UNDERFLOW\n");
    }
    else{
        int output;
        output=pntr_to_cq->a[pntr_to_cq->front];
        pntr_to_cq->a[pntr_to_cq->front]=0;
        pntr_to_cq->front=(pntr_to_cq->front+1)%MAX;
        return output;
    }
    return -1;
}
void print(circular_queue cq){
    if(isempty(cq)){
        return;
    }
    if(cq.front<cq.rear){
        for(int i=cq.front;i<cq.rear;i++){
            printf("%d,",cq.a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<cq.rear;i++){
        printf("%d,",cq.a[i]);
    }
    for(int i=cq.front;i<MAX;i++){
        printf("%d,",cq.a[i]);
    }
    printf("\n");
}
int main(){
    circular_queue cq1;
    initialize(&cq1);
    print(cq1);
    inqueue(&cq1,10);
    print(cq1);
    inqueue(&cq1,20);
    print(cq1);
    inqueue(&cq1,30);
    print(cq1);
    inqueue(&cq1,40);
    print(cq1);
    inqueue(&cq1,50);
    print(cq1);
    inqueue(&cq1,60);
    print(cq1);
    inqueue(&cq1,70);
    print(cq1);
    inqueue(&cq1,80);
    print(cq1);
    inqueue(&cq1,90);
    print(cq1);
    inqueue(&cq1,90);
    print(cq1);
    dequeue(&cq1);
    dequeue(&cq1);
    print(cq1);
    inqueue(&cq1,90);
    print(cq1);
    inqueue(&cq1,90);
    print(cq1);
    inqueue(&cq1,90);
    print(cq1);
}