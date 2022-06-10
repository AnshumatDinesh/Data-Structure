#include <stdio.h>
#include <stdlib.h>
struct node
{
  int value;
  struct node *next;
};
void initialize(struct node **head, int num)
{
  /*
  This function initalizes the head of the linked list
  */
  //Assigning memory space equivalent to that taken by one struct node to\
  //the head
  *(head) = (struct node *)malloc(sizeof(struct node));
  // Setting the value of the next of the node pointed to by the head to
  // NULL
  // and setting its value to the given num
  (*(head))->next = NULL;
  (*(head))->value = num;
}
void push_f(struct node **head, int num)
{
  /*
  This function pushes nodes from the front of the linked list
  */
  if ((*head) == NULL)
  {
    // Checking for an unintialized or empty linked list
    // this case can arise if if we
    // pop all the lement of an initialised list
    // put an uninitialized list into the function
    // so we call the initialise function on head
    initialize(head, num);
    return;
  }
  // creating a new node and assigning it the given value
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  (*new_node).value = num;
  // setting its next pointer to the node pointed to by the head
  // ie now the previous first element
  (*new_node).next = (*head);
  // setting the head pointer pointing to the new first value
  *(head) = new_node;
}
void append(struct node **head, int num)
{
  /*
  This function adds the element at the of the list
  */
  if ((*head) == NULL)
  {
    // Checking for an unintialized or empty linked list
    // this case can arise if if we
    // pop all the lement of an initialised list
    // put an uninitialized list into the function
    // so we call the initialise function on head
    initialize(head, num);
    return;
  }
  // Declaring the new node and setting its value equal to given value
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  (*new_node).value = num;
  (*new_node).next = NULL; // setting its pointer to next as  NULL
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != NULL)
  {
    pntr_nxt = (*pntr_nxt).next;
  }
  // setting the next pointer of the last element to the new node;
  (*pntr_nxt).next = new_node;
}
void insert(struct node **head, int index, int num)
{
  /*
  This function inserts the element after the given index
  */
  if ((*head) == NULL)
  {
    // Checking for an unintialized or empty linked list
    // this case can arise if if we
    // pop all the lement of an initialised list
    // put an uninitialized list into the function
    // so we call the initialise function on head
    initialize(head, num);
    return;
  }
  // declaring a variable count to keep track of the nodes
  int count = 0;
  // Declaring the new node and setting its value equal to given value

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  (*new_node).value = num;
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != NULL)
  {
    if (count == index)
    {
      // if we rech the index the loop should break;
      break;
    }
    // else it will go on till either of the terminating conditions are satisfied
    pntr_nxt = (*pntr_nxt).next;
    count++;
  }
  (*new_node).next = (*pntr_nxt).next;
  (*pntr_nxt).next = new_node;
}
int get(struct node **head, int index)
{
  /*
  This function gests the value of the element at the index place given
  */
  // declaring a variable count to keep track of the nodes
  int count = 0;
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while (pntr_nxt != NULL)
  {
    if (count == index)
    {
      // if we reach the index we return the value
      return (*pntr_nxt).value;
    }
    pntr_nxt = (*pntr_nxt).next;
    count++;
  }
  // if the index is outside the scope of the list we reteun
  // error code 404
  return 404;
}
int pop(struct node **head)
{
  /*
  This function removes the last element of the list and returns it
  */
  if ((*head) == NULL)
  {
    // checking for underflow
    // and returning and error if true
    return 404;
  }
  if ((*head)->next == NULL)
  {
    // if the list only has one element the
    // generalised solution does not work
    int out = (*head)->value;
    (*head) = NULL;
    return out;
  }
  // traversing to the last element
  struct node *pntr_nxt = *head;
  while ((*(*pntr_nxt).next).next != NULL)
  {
    pntr_nxt = (*pntr_nxt).next;
  }
  // storing the value of the last element in a temp
  int out = (*(*pntr_nxt).next).value;
  // setting the next of the prev element to NULL
  (*pntr_nxt).next = NULL;
  // returning the poped element's value
  return out;
}
int pop_f(struct node **head)
{
  /*
  This function removes the first element of the list and returns it
  */
  if ((*head) == NULL)
  {
    // checking for underflow
    // and returning and error if true
    return 404;
  }
  // storing the first element in a temp
  int out;
  out = (*(*head)).value;
  // redirecting head to the second value
  (*head) = (*(*head)).next;
  // returning the temp
  return out;
}
int del(struct node **head, int index)
{
  /*
  This function deletes the element at index and returns it
  */
  if ((*head) == NULL)
  {
    // checking for underflow
    // and returning and error if true
    return 404;
  }
  // declaring a variable count to keep track of the nodes
  int count = 0;
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != NULL)
  {
    if (count == index - 1)
    {
      // if we rech the index the loop should break;
      break;
    }
    // else it will go on till either of the terminating conditions are satisfied
    pntr_nxt = (*pntr_nxt).next;
    count++;
  }
  int out = ((*pntr_nxt).next)->value;
  (*pntr_nxt).next = (*(*pntr_nxt).next).next;
  return out;
}
void clear(struct node **head)
{
  /*
  This function clears a list
  */
  while (pop(head) != 404)
  {
  }
}
void random(struct node **head,int size){
  /*
  This function fills a list with random numbers
  */
  for(int i=0;i<size;i++){
    int rndm_num=rand()%100;
    append(head,rndm_num);
  }
}
void print(struct node *head)
{
  struct node *pntr_nxt = head;
  while (pntr_nxt != NULL)
  {
    printf("%d-->", (*pntr_nxt).value);
    pntr_nxt = (*pntr_nxt).next;
  }
  printf("NULL\n");
}
void concatenate(struct node **head1,struct node **head2){
  /*
  This funtion concatenates 2 linked lists
  */
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head1;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != NULL)
  {
    pntr_nxt = (*pntr_nxt).next;
  }
  (*pntr_nxt).next = (*head2);
}    
int main()
{
  struct node *head;
  initialize(&head, 10);
  print(head);
  push_f(&head, 9);
  print(head);
  append(&head, 11);
  print(head);
  append(&head, 13);
  print(head);
  printf("%d\n", get(&head, 0));
  printf("%d\n", get(&head, 1));
  printf("%d\n", get(&head, 2));
  printf("%d\n", get(&head, 3));
  printf("%d\n", get(&head, 4));
  insert(&head, 2, 12);
  print(head);
  printf("%d\n", pop(&head));
  print(head);
  printf("%d\n", pop(&head));
  printf("%d\n", pop(&head));
  printf("%d\n", pop(&head));
  printf("%d\n", pop(&head));
  printf("%d\n", pop(&head));
  print(head);
  append(&head, 0);
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);
  append(&head, 5);
  append(&head, 6);
  append(&head, 7);
  append(&head, 8);
  print(head);
  printf("%d\n", del (&head, 4));
  print(head);
  clear(&head);
  print(head);
  random(&head,10);
  print(head);
  struct node *head1,*head2;
  initialize(&head1,0);
  initialize(&head2,1);
  random(&head1,5);
  random(&head2,5);
  print(head1);
  print(head2);
  concatenate(&head1,&head2);
  print(head1);


  

}