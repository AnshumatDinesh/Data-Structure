#include "buble_sort.c"
int main(){
    int *pntr_to_arr;
    int n=10;
    pntr_to_arr=(int*)malloc(n*sizeof(int));
    random(pntr_to_arr,n);
    buble_sort(pntr_to_arr,n);

}