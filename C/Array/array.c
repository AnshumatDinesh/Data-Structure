#include <stdio.h>
#include <stdlib.h>
typedef struct arr{
    int *p;
    int len;
    int max;
}array;
array initialize(array a1){
    a1.p = (int*) calloc(a1.max,sizeof(int));
    a1.len=0;
    return  a1;
}
int append(array *a1,int val){
    if((*a1).len+1>(*a1).max){
        return 0;
    }
    *((*a1).p+(*a1).len)=val;
    (*a1).len++;
    return 1;
}
int rem(array *a1,int val){
    int found=0;
    if((*a1).len-1<0){
        return 0;
    }
    int i;
    for(i=0;i<(*a1).len;i++){
        if(*((*a1).p+i)==val){
            found=1;
            break;
        }
    }
    for(int j=i;j<(*a1).len-1;j++){
        *((*a1).p+j)=*((*a1).p+j+1);
    }
    if(found==1){
        (*a1).len--;
    }
    
    return found;
}
void remAll(array *a1,int val){
    int old_len=(*a1).len;
    while(rem(a1,val)==1){
    }

}
void print(array a1){
    for (int i=0;i<a1.len-1;i++){
        printf("%d,",*(a1.p+i));
    }

    printf("%d\n",*(a1.p+a1.len-1));
}
int linear_search(array a1,int query){
    /*
    This funtion searches all thee elments of an array
    and returns index of the first instance of the element 
    */
    for (int i=0;i<a1.len-1;i++){
        if(*(a1.p+i)==query){
            return i;
        }
    }
}