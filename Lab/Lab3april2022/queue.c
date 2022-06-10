#include <stdio.h>
#include <stdlib.h>
int dequeue(int *queue,int *rear){
    if(*(rear)==-1){
        printf("UNDERFLOW\n");
        return-1;
    }
    int out=queue[0];
    for (int i=1;i<*(rear)+1;i++){
        queue[i-1]=queue[i];
    }

    int tp=*rear;
    *rear=tp-1;
    return out;
}
void inqueue(int *queue,int value,int *rear,int max){
    int tp=*rear;
    *rear=tp+1;
    if(*rear>max){
        printf("OVERFLOW\n");
        *rear=tp;
        return;

    }
    *(queue+*rear)=value;

}
void print(int queue[],int rear){
    for(int i=0;i<=rear;i++){
        printf("%d,",queue[i]);
    }
    printf("\n");
}
int main(){
    int max=10;
    int q1[max];
    int rear=-1;
    inqueue(q1,10,&rear,max);
    inqueue(q1,2,&rear,max);
    inqueue(q1,40,&rear,max);
    inqueue(q1,6,&rear,max);
    inqueue(q1,7,&rear,max);
    inqueue(q1,7,&rear,max);
    inqueue(q1,13,&rear,max);
    inqueue(q1,16,&rear,max);
    inqueue(q1,132,&rear,max);
    inqueue(q1,34,&rear,max);
    print(q1,rear);
    dequeue(q1,&rear);
    dequeue(q1,&rear);
    dequeue(q1,&rear);
    dequeue(q1,&rear);
    print(q1,rear);
    inqueue(q1,33,&rear,max);
    inqueue(q1,23,&rear,max);
    print(q1,rear);

}