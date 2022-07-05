#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define OR ||
#define AND &&
typedef struct q{
    int *arr;
    int front;
    int rear;
}circular;
void initialize(circular * pntr_c){
    (* pntr_c).arr=(int*)malloc(SIZE*sizeof(int));//creating array of size 10
    (* pntr_c).front=-1;//initialize front to -1
    (* pntr_c).rear=-1;//initialize rear to -1
}
int is_full(circular c){
    /*
    checks if the queue is full
    */
    if ((c.front==c.rear+1)OR(c.front==0 AND c.rear==SIZE-1)){
        return 1;

    }
    return 0;
}
int is_empty(circular c){
    /*
    checks if the queue is empty
    */
    if (c.front==-1){
        return 1; 
    }
    return 0;
}
int enqueue(circular * pntr_c, int val){
    /*
    A function to add elements at the rear of the circular queue
    */
    if(is_full(*pntr_c)){
        printf("OVERFLOW\n");
        return 0;
    }
    if( (*pntr_c).front==-1){
        (*pntr_c).front=0;
    }
    (*pntr_c).rear=((*pntr_c).rear+1)%SIZE;//incrementing rear in a loop
    *((*pntr_c).arr+(*pntr_c).rear)=val;//if the rear exceeds the size, it is reduced by
    return 1;//modulus
}
int dequeue(circular * pntr_c){
    /*
    A function to add elements at the rear of the circular queue
    */
    int out;
    if(is_empty((*pntr_c))){
        printf("UNDERFLOW\n");
        return NULL;

    }
    out=*((*pntr_c).arr+(*pntr_c).front);
    *((*pntr_c).arr+(*pntr_c).front)=-999;//deleting the value held by pointer
    if ((*pntr_c).front==(*pntr_c).rear){
        (*pntr_c).front=-1;
        (*pntr_c).rear=-1;
        return out;
    }
    (*pntr_c).front++;//incrementing front in a loop
    (*pntr_c).front%=SIZE;//if the front exceeds the size, it is reduced by
    return out;//modulus
}
void print(circular * pntr_c){
    if(is_empty(* pntr_c)){
        return;
    }
    if ((*pntr_c).front<=(*pntr_c).rear){
        for(int i=(*pntr_c).front;i<=(*pntr_c).rear;i++){
            printf("%d,",*((*pntr_c).arr+i));
        }
        printf("\n");
        return;
    }
    for(int i=0;i<SIZE;i++){
        if (*((*pntr_c).arr+i)!=-999){
        printf("%d,",*((*pntr_c).arr+i));
        }
    }
    printf("\n");
}
int main(){
    circular c1;
    initialize(&c1);
    enqueue(&c1,1);
    print(&c1);
    enqueue(&c1,2);
    print(&c1);
    enqueue(&c1,3);
    print(&c1);
    enqueue(&c1,4);
    print(&c1);
    enqueue(&c1,5);
    print(&c1);
    enqueue(&c1,6);
    print(&c1);
    enqueue(&c1,7);
    print(&c1);
    enqueue(&c1,8);
    print(&c1);
    enqueue(&c1,9);
    print(&c1);
    enqueue(&c1,10);
    print(&c1);
    dequeue(&c1);
    print(&c1);
    dequeue(&c1);
    print(&c1);
    dequeue(&c1);
    print(&c1);
    enqueue(&c1,13);
    print(&c1);
    enqueue(&c1,14);
    print(&c1);
    enqueue(&c1,15);
    print(&c1);
}