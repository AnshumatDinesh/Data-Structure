#include "sorting_essential.c"
void buble_sort(int *pntr,int len){
    for(int i=0;i<len;i++){
        printf("%dth iteration\n",i);
        print(pntr,len);
        for(int j=0;j<len-i-1;j++){
            if(*(pntr+j)>*(pntr+j+1)){
                printf("Swaping %dth and %dth element\n",j,j+1);
                swap(pntr+j,pntr+j+1);
                print(pntr,len);

            }
        }
    }
}
void buble_sort_rec(int *pntr,int low,int high,int len){
    if (low>high){
        return;
    }
    printf("%dth recursion\n",len-high);
    print(pntr,high);
    for(int j=0;j<len-low-1;j++){
            if(*(pntr+j)>*(pntr+j+1)){
                printf("Swaping %dth and %dth element\n",j,j+1);
                swap(pntr+j,pntr+j+1);
                print(pntr,high);

            }
        }
    return buble_sort_rec(pntr,low,high-1,len);
}