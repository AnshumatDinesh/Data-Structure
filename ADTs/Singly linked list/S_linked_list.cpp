#include<iostream>
#include <limits>
using namespace std;

class node{
    public:
        int data;
        node * next;
};
class linkedList{
    private:
    public:
        node *head;
    linkedList(){
        head=nullptr;
    }
    void append(int val){
        node *newNode;
        newNode=(node*)malloc(sizeof(node));
        newNode->data=val;
        if (head=NULL){
            head=newNode;
        }
    }
    void print(){
        node * nxt;
        nxt=head;
        while(nxt!=NULL){
            cout<<nxt->data<<"-->";
            nxt=nxt->next;
        }
        cout<<"NULL\n";
    }
};
int main(){
    linkedList ll1;
    ll1.append(10);
    ll1.print();
}