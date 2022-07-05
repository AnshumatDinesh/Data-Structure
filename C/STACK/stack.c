#include <stdio.h>
#include <stdlib.h>
#define AND &&
#define OR ||
typedef struct stack
{
    int *pntr;
    int height;
}Stack;
void initialize(Stack *pntr_to_stck){
    /*
    This function sets up the initial condition for a stack
    allocates memory and sets height to 0
    */
    (*pntr_to_stck).pntr = (int*) malloc(100 * sizeof(int));
    (*pntr_to_stck).height=0;
}
void push(Stack *pntr_to_stck,int num_to_be_pushed){
    /*
    The last element in the stack is stored height-1 away from the starting pointer 
    so  we will add the new element at distance equal to the height of the stack
    Here, pntr_to_stck is the pointer to the stack structure that we have declared
    */
    *((*pntr_to_stck).pntr+(*pntr_to_stck).height)=num_to_be_pushed;
    //stck
    //*pntr--> stck
    //stck.pntr
    //now we increase the length of the stack by one
    (*pntr_to_stck).height+=1;
}
void print(Stack *pntr_to_stck){
    /*
    This function prints the elements of the stack in a comma seperated form
    */
    for(int i=0;i<(*pntr_to_stck).height;i++){
        printf("%d,",*((*pntr_to_stck).pntr+i));
    }
    printf("\n");
}
int isempty(Stack *pntr_to_stck){
    if ((*pntr_to_stck).height==0){
        return 1;
    }
    return 0;
}
int pop(Stack *pntr_to_stck){
    /*
    This function pops the last element of the stack and 
    returns it 
    */
    if(isempty(pntr_to_stck)){
        return -1;
    }
    int temp_poped_element=*((*pntr_to_stck).pntr+(*pntr_to_stck).height-1);
    (*pntr_to_stck).height-=1;
    return temp_poped_element;
}
void pushb(Stack *pntr_to_stck,int len_of_array,int *arr_pntr){
    /*
    This function pushes all the elements of an array 
    into the stack
    */
    for(int i=0;i<len_of_array;i++){
        push(pntr_to_stck,*(arr_pntr+i));
    }
}
void random(Stack *pntr_to_stck,int num_to_be_inserted){
    for(int i=0;i<num_to_be_inserted;i++){
        //generating a random number generator between 0-99
        int rndm_num=rand()%100;
        push(pntr_to_stck,rndm_num);
    }
}
int peek(Stack *pntr_to_stck){
    int temp_poped_element=*((*pntr_to_stck).pntr+(*pntr_to_stck).height-1);
    return temp_poped_element;
}
void delete_stack(Stack *pntr_to_stck){
    free(pntr_to_stck->pntr);
}