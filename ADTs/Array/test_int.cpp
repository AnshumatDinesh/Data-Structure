#include"array.cpp"
int main(){
    Array arr(10);
    for(int i=0;i<10;i++){
        arr.append(i);
        arr.print();
    }
    arr.expand(30);
    for(int i=0;i<20;i++){
        arr.append(i);
        arr.print();
    }
    arr.insert(10,1);
    arr.print();
}