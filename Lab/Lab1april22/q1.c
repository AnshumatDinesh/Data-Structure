#include <stdio.h>
#include <stdlib.h>
void swap(int *pntr1,int*pntr2){
    int temp= *pntr1;
    *pntr1=*pntr2;
    *pntr2=temp;
}
int smallest(int*pntr,int length){
    int small=*pntr;
    for(int i=0;i<length;i++){
        if (*(pntr+i)<small){
            small=*(pntr+i);
        }
    }
    return small;
}
int largest(int*pntr,int length){
    int big=*pntr;
    for(int i=0;i<length;i++){
        if (*(pntr+i)>big){
            big=*(pntr+i);
        }
    }
    return big;
}
int large_second_large(int*pntr,int length){
    int l=largest(pntr,length);
    int second_big=*pntr;
    for(int i=0;i<length;i++){
        if (*(pntr+i)>second_big && *(pntr+i)<l){
            second_big=*(pntr+i);
        }
    }
    return l-second_big;
}

void print(int*pntr,int length){
    for(int i=0;i<length;i++){
        printf("%d,",*(pntr+i));
    }
    printf("\n");
}
void buble_sort(int*pntr,int length){
    for(int i=0; i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(*(pntr+j)>*(pntr+j+1)){
                swap(pntr+j,pntr+j+1);
            }
        }
        print(pntr,length);
    }
}
void selection_sort(int*pntr,int length){
    for(int i=0; i<length;i++){
        int min_index=i;
        for(int j=0+i;j<length;j++){
            if(*(pntr+j)<*(pntr+min_index)){
                min_index=j;
            }
        }
        swap(pntr+i,pntr+min_index);
    }
}
void insertion_sort(int*pntr,int length){
    for(int i=1; i<length;i++){
        int j=i-1;
        int key=*(pntr+i);
        while(j>=0 && *(pntr+j)>key){
            *(pntr+j+1)=*(pntr+j);
            j--;
        }
        *(pntr+j+1)=key;
    }
    
}
int main(){
    int a[]={9,8,7,6,5,4,3,2,1};
    // printf("%d\n",smallest(a,7));
    // printf("%d\n",largest(a,7));
    // printf("%d\n",large_second_large(a,7));
    buble_sort(a,9);
    // print(a,7);
    // int b[]={2,4,3,9,8,1,6};
    // selection_sort(b,7);
    // print(b,7);
    // int c[]={2,4,3,9,8,1,6};
    // insertion_sort(c,7);
    // print(c,7);
}