#include <stdio.h>
#include <stdlib.h>
int pop(int *stack,int *top){
    if(*(top)==-1){
        printf("UNDERFLOW\n");
        return-1;
    }
    int out=stack[*(top)];
    int tp=*top;
    *top=tp-1;
    return out;
}
int peek(int *stack,int *top){
    if(*(top)==-1){
        printf("UNDERFLOW\n");
        return-1;
    }
    int out=stack[*(top)];
    return out;
}
void push(int *stack,int value,int *top,int max){
    int tp=*top;
    *top=tp+1;
    if(*top>max){
        printf("OVERFLOW\n");
        *top=tp;
        return;

    }
    *(stack+*top)=value;

}
void print(int stack[],int top){
    for(int i=0;i<=top;i++){
        printf("%d,",stack[i]);
    }
    printf("\n");
}
int main(){
    int max=10;
    int s1[max];
    int top=-1;
    push(s1,10,&top,max);
    push(s1,2,&top,max);
    push(s1,40,&top,max);
    push(s1,6,&top,max);
    push(s1,7,&top,max);
    push(s1,7,&top,max);
    push(s1,13,&top,max);
    push(s1,16,&top,max);
    push(s1,132,&top,max);
    push(s1,34,&top,max);
    print(s1,top);
    // pop(s1,&top);
    // pop(s1,&top);
    // pop(s1,&top);
    // printf("%d\n",peek(s1,&top));
    // print(s1,top);
}