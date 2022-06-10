#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
void random(int *pntr,int len){
    for(int i=0;i<len;i++){
        int rndm=rand()%100;
        *(pntr+i)=rndm;
    }
}
void swap(int *pntr1,int *pntr2){
    int temp=*pntr1;
    *pntr1=*pntr2;
    *pntr2=temp;
}
void print(int*pntr,int len){
    for(int i=0;i<len;i++){
        printf("%d,",*(pntr+i));
    }
    printf("\n");
}