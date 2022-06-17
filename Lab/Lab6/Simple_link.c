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
  struct node *pntr_temp = pntr_nxt->next;
  // setting the next of the prev element to NULL
  (*pntr_nxt).next = NULL;
  free(pntr_temp);
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
  struct node *pntr_temp = *head;
  int out;
  out = (*(*head)).value;
  // redirecting head to the second value
  (*head) = (*(*head)).next;
  free(pntr_temp);
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
  struct node *pntr_temp = pntr_nxt->next;
  (*pntr_nxt).next = (*(*pntr_nxt).next).next;
  free(pntr_temp);
  return out;
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
int count(struct node *head){
    struct node *pntr_nxt = head;
    int count=0;
    while (pntr_nxt != NULL)
    {
        count++;
        pntr_nxt = (*pntr_nxt).next;
    }
    return count;
}
void reverse(struct node **head){
    if((*head)=NULL){
        printf("CANT REVERSE EMPTY LIST\n");
        return;
    }
    struct node *ptr_curr=*head;//current pointer as head
    struct node *ptr_prev=NULL;//previous and next pointer as null
    struct node *ptr_nxt=NULL;
    while(ptr_curr->next!=NULL){
        ptr_nxt=ptr_curr->next;//storing the address of the current next in next pointer
        ptr_curr->next=ptr_prev;//assigning the next of current the address of the previous node
        ptr_prev=ptr_curr;//now set the previous node as current
        ptr_curr=ptr_nxt;//and current as the next node beforwe switching
    }
    *head=ptr_prev;//moving the head to the last node
}
int main(){
    int runner=1,menu;
    struct node *head;
    while(runner){
        printf("0.Exit\n");
        printf("1.Create a link list\n");
        printf("2.Insert a node at begining\n");
        printf("3.Insert a node at a given index\n");
        printf("4.Insert a node at end\n");
        printf("5.Delete a node at begining\n");
        printf("6.Delete a node at a given index\n");
        printf("7.Delete a node at a end\n");
        printf("8.Display the list\n");
        printf("9.Count of node\n");
        printf("10.Reverse a list\n");
        scanf("%d",&menu);
        int num,ind;
        switch(menu){
            case 0:
                runner=0;
                break;
            case 1:
                int init_val;
                printf("Enter  value of first node");
                scanf("%d",&init_val);
                initialize(&head,init_val);
                printf("Created a linked list with first node of value %d\n",init_val);
                break;
            case 2:
                printf("Enter  value: ");
                scanf("%d",&num);
                push_f(&head,num);
                printf("Added %d to the front of the list \n",num);
                break;
            case 3:
                printf("Enter  value: ");
                scanf("%d",&num);
                printf("Enter the  index: ");
                scanf("%d",&ind);
                insert(&head,ind,num);
                printf("Added %d at %dth index of the list \n",num,ind);
                break;
            case 4:
                printf("Enter  value: ");
                scanf("%d",&num);
                append(&head,num);
                printf("Added %d to the back of the list \n",num);
                break;
            case 5:
                pop_f(&head);
                printf("Deleted the first node \n");
                break;
            case 6:
                printf("Enter the  index: ");
                scanf("%d",&ind);
                del(&head,ind);
                printf("Deleted the %dth node \n",ind);
                break;
            case 7:
                pop(&head);
                printf("Deleted the last node \n");
                break;
            case 8:
                print(head);
                break;
            case 9:
                printf("The number of nodes is %d\n",count(head));
                break;
            case 10:
                reverse(&head);
                printf("Reversed the List \n");
                break;
        }
    }
}