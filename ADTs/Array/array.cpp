#include<iostream>
#include <limits>
using namespace std;
/*
This class defines an array of integers
*/
class Array{
    private:
        int size;
        int max;
        int *pntr;
    public:
    Array(int maximun){
        size=0;
        max=maximun;
        pntr=(int *)malloc(max*sizeof(int));
    }
    /*
    This function adds an element ot the end of the array
    Returns 0 if the function encounters overflow
    */
    int append(int num){
        if (size+1>max){//Overflow
            return 0;
        }
        *(pntr+size)=num;
        size++;
        return 1;
    }
    /*
    This function prints the contents of an array in a organized manner
    */
    int print(){
        for(int i=0;i<size-1;i++){
            cout<<*(pntr+i)<<',';
        }
        if(size>=1){
            cout<<*(pntr+size-1)<<endl;
        }
        else{
            cout<<endl;
        }
        
        return 1;
    }
    /*
    This function inserts a number after the stated index
    returns 0 if it encounters overflow or if the given index exeeds the maximum size
    */
    int insert(int index,int num){
        if (size+1>max){//Overflow
            return 0;
        }
        if (index>max){//index exeeds maximum
            return 0;
        }
        if(index==size){//index exeeds current size
            append(num);
        }
        for (int i=size-1;i>=index;i--){
            *(pntr+i+1)=*(pntr+i);
        }
        *(pntr+index)=num;
        size++;
        return 1;
    }
    /*
    This function removes the last element of the array and returns it
    If an error is encountered it returns -1*infinity
    */
    int pop(){
        if (size==0){
            return numeric_limits<int>::min();
        }
        int output;
        output=*(pntr+size-1);
        size--;
        return output;
    }
    /*
    This function removes the element at the given index and returns its value
    If an error is encountered it returns -1*infinity
    */
    int remove(int index){
        if (size==0){
            return numeric_limits<int>::min();
        }
        if (index>size){
            return numeric_limits<int>::min();
        }
        if(index==size){
            return pop();
        }
        int output=*(pntr+index);
        for(int i=index;i<size;i++){
            *(pntr+i)=*(pntr+i+1);
        }
        size--;
        return output;
    }
    /*
    Erases the array and frees the space occupied by it
    */
    void erase(){
        size=0;
        free(pntr);
    }
    /*
    Returns the value stored at a given index 
    */
    int element(int index){
        return *(pntr+index);
    }
    /*
    Returns the length of the array
    */
    int length(){
        return size;
    }
    /*
    This function expands the maximum space available for the array
    */
    void expand(int max_new){
        max=max_new;
        pntr=(int*)realloc(pntr,max_new*sizeof(int));
    }

};