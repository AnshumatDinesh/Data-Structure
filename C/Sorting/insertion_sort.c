#include "sorting_essential.c"
void insertion_sort(int *pntr,int len){
    for(int i=1;i<len;i++){
        printf("%dth iteration\n",i);
        print(pntr,len);
        int j=i;
        while(*(pntr+j)<*(pntr+j-1) && j!=0){
            printf("Swaping %dth and %dth element\n",j,j-1);
            swap(pntr+j,pntr+j-1);
            print(pntr,len);
            j--;
        }
    }
}