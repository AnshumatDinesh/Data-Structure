#include "array.c"
int main(){
    array arr1;
    arr1.max=100;
    arr1 = initialize(arr1);
    append(&arr1,12);
    append(&arr1,10);
    append(&arr1,14);
    append(&arr1,11);
    append(&arr1,3);
    append(&arr1,5);
    append(&arr1,14);
    append(&arr1,8);
    append(&arr1,14);
    append(&arr1,6);
    append(&arr1,1);
    print(arr1);
    remAll(&arr1,14);
    print(arr1);
}