
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct de_q{
    int *arr;
    int front;
    int rear;
}de_queue;
void initialize(de_queue *pntr_de){
    (*pntr_de).arr=(int*)calloc(MAX,sizeof(int));
    (*pntr_de).front=-1;
    (*pntr_de).rear=-1;

}
int count(int *arr) {
  int c = 0;

  for (int i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}
void addFront(de_queue *pntr_de, int item) {
  if ((*pntr_de).front == 0 && (*pntr_de).rear == MAX - 1) {
    printf("OVERFLOW\n");
    return;
  }

  if ((*pntr_de).front == -1) {
    (*pntr_de).front = 0;
    (*pntr_de).rear = 0;
    *((*pntr_de).arr+((*pntr_de).front)) = item;
    return;
  }

  if ((*pntr_de).rear != MAX - 1) {
    int c = count((*pntr_de).arr);
    int k = (*pntr_de).rear + 1;
    for (int i = 1; i <= c; i++) {
      (*pntr_de).arr[k] = (*pntr_de).arr[k - 1];
      k--;
    }
    (*pntr_de).arr[k] = item;
    (*pntr_de).front = k;
    ((*pntr_de).rear)++;
  } else {
    ((*pntr_de).front)--;
    (*pntr_de).arr[(*pntr_de).front] = item;
  }
}

void addRear(de_queue *pntr_de, int item) {
  int i, k;

  if ((*pntr_de).front == 0 && (*pntr_de).rear == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if ((*pntr_de).front == -1) {
    (*pntr_de).rear = 0;
    (*pntr_de).front = 0;
    (*pntr_de).arr[(*pntr_de).rear] = item;
    return;
  }

  if ((*pntr_de).rear == MAX - 1) {
    k = (*pntr_de).front - 1;
    for (i = (*pntr_de).front - 1; i < (*pntr_de).rear; i++) {
      if (i == MAX - 1)
        (*pntr_de).arr[i] = 0;
      else
        (*pntr_de).arr[i] = (*pntr_de).arr[i + 1];
    }
    ((*pntr_de).rear)--;
    ((*pntr_de).front)--;
  }
  ((*pntr_de).rear)++;
  (*pntr_de).arr[(*pntr_de).rear] = item;
}

int delFront(de_queue *pntr_de) {
  int item;

  if ((*pntr_de).front == -1) {
    printf("UNDERFLOW\n");
    return 0;
  }

  item = *((*pntr_de).arr+((*pntr_de).front));
  *((*pntr_de).arr+((*pntr_de).front))= 0;

  if ((*pntr_de).front == (*pntr_de).rear){
    (*pntr_de).front = -1;
    (*pntr_de).rear = -1;}
  else
    ((*pntr_de).front)++;

  return item;
}

int delRear(de_queue *pntr_de) {
  int item;

  if ((*pntr_de).front == -1) {
    printf("UNDERFLOW\n");
    return 0;
  }

  item = *((*pntr_de).arr+((*pntr_de).rear));
  *((*pntr_de).arr+((*pntr_de).rear)) = 0;
  ((*pntr_de).rear)--;
  if ((*pntr_de).rear == -1)
    (*pntr_de).front = -1;
  return item;
}

void display(de_queue *pntr_de) {
  int i;

  printf("\n front:  ");
  for (i = 0; i < MAX; i++)
    printf("  %d", *((*pntr_de).arr+i));
  printf("  :rear");
}


int main() {
    de_queue de1;
    initialize(&de1);

  addRear(&de1,5);
  addRear(&de1,6);
  addRear(&de1,7);
  addRear(&de1,8);
  addFront(&de1,1);
  addFront(&de1,2);
  display(&de1);
  delFront(&de1);
  display(&de1);
  delRear(&de1);
  display(&de1);
}


