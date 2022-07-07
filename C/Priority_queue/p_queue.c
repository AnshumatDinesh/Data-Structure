#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct item{
    int value;
    int priority;
};
struct p_queue{
    struct item* arr;
    int size;
};
void swap(struct item* a,struct item* b){
    struct item temp;
    temp.priority=a->priority;
    temp.value=a->value;
    a->priority=b->priority;
    a->value=b->value;
    b->priority=temp.priority;
    b->value=temp.value;
    return;
}
void sort(struct p_queue *pq){
    for(int i=0;i<=pq->size+1;i++){
        for(int j=i;j<pq->size-i;j++){
            if(pq->arr[j].priority>pq->arr[j+1].priority){
                swap(((pq->arr)+j),((pq->arr)+j+1));
            }
        }
    }
}
void initialize(struct p_queue *pq){
    pq->arr=(struct item*)malloc(MAX*sizeof(struct item));
    pq->size=-1;
}
void enqueue(struct p_queue *pq,int val,int pri){
    if(pq->size==MAX){
        printf("OVERFLOW\n");
        return;
    }
    pq->size++;
    pq->arr[pq->size].value=val;
    pq->arr[pq->size].priority=pri;
    sort(pq);
}
int peek(struct p_queue *pq){
    int pri_max=INT_MIN;
    int ind_max=-1;
    for(int i=0;i<=pq->size;i++){
        if(pri_max==pq->arr[i].priority && ind_max>-1 && pq->arr[ind_max].value<pq->arr[i].value){
            pri_max=pq->arr[i].priority;
            ind_max=i;
        }
        else if(pri_max<pq->arr[i].priority){
            pri_max=pq->arr[i].priority;
            ind_max=i;
        }
    }
    return ind_max;
}
void dequeue(struct p_queue *pq){
    if(pq->size==-1){
        return ;
        }
    int ind=peek(pq);
    for (int i = ind; i < pq->size; i++) {
        pq->arr[i] = pq->arr[i+1];
    }
    pq->size--;
    
}
void print(struct p_queue *pq){
    for(int i=0;i<=pq->size;i++){
        printf("Value:%d\tPriority:%d\n",pq->arr[i].value,pq->arr[i].priority);
    }
}
int main(){
    struct p_queue pq1;
    initialize(&pq1);
    enqueue(&pq1,10,5);
    enqueue(&pq1,11,4);
    enqueue(&pq1,12,3);
    enqueue(&pq1,13,2);
    enqueue(&pq1,14,1);
    enqueue(&pq1,15,6);
    print(&pq1);
}