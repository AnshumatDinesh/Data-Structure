#include<stdio.h>
#include<stdlib.h>
int main(){
    int *pntr;
    pntr=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;i++){
        //a[i]-->*(a+i)
        *(pntr+i)=i*i;
    }
    for(int i=0;i<10;i++){
        //a[i]-->*(a+i)
        printf("%d,",*(pntr+i));
    }
}