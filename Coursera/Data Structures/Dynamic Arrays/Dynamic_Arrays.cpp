#include <iostream>
using namespace std;
class Dynamic_Arr{
    private:
        int size;
        int capacity;
        int *begin;
        void expand(){
            capacity*=2;
            realloc(begin,capacity*sizeof(int));
        }
    public:
    Dynamic_Arr(int cap){
        size=0;
        capacity=cap;
        begin=(int *) malloc(capacity*sizeof(int));
    }
    void set(int index,int val){
        if(index>=capacity){
            expand();
        }
        *(begin+index)=val;

    }
    int get(int index){
        if(index>=capacity){
           return -1;
        }
        return *(begin+index);
    }
};
int main(){
    Dynamic_Arr arr1(2);
    for(int i=0;i<5;i++){
        arr1.set()
    }
}