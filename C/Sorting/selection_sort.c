#include "sorting_essential.c"
void selection_sort(int *pntr,int len){
    for(int i=0;i<len;i++){
        printf("%dth iteration\n",i);
        print(pntr,len);
        int min=i;
        for(int j=i;j<len;j++){
            if(*(pntr+min)>*(pntr+j)){
                min=j;
                printf("new minimum element is the %dth with value %d\n",j,*(pntr+j));

            }
        }
        printf("swaping %dth with  %dth \n",min,i);
        swap(pntr+i,pntr+min);
    }
}