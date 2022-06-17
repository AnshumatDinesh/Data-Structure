#include <stdio.h>
#include <stdlib.h>
struct node
{
    char *name;
    int age;
    char *adress;
    struct node *next;
};
void initialize(struct node **head, int num,char *name,char *adress )
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
  (*(head))->next = *head;
  (*(head))->age = num;
  (*(head))->adress=adress;
  (*head)->name=name;
}
void enqueue(struct node **head, int num,char *name,char *adress )
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
    initialize(head, num,name,adress);
    return;
  }
  // Declaring the new node and setting its value equal to given value
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  (*new_node).age = num;
  (*new_node).name = name;
  (*new_node).adress = adress;
  (*new_node).next = *head; // setting its pointer to next as  NULL
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != *head)
  {
    pntr_nxt = (*pntr_nxt).next;
  }
  // setting the next pointer of the last element to the new node;
  (*pntr_nxt).next = new_node;
}
void dequque(struct node **head)
{
  /*
  This function removes the first element of the list and returns it
  */
  if ((*head) == NULL)
  {
    // checking for underflow
    // and returning and error if true
    return ;
  }
  // creating a pointer for traversing the list  and setting its initial value
  // equal to the adress of the first element
  struct node *pntr_nxt = *head;
  // if the next pointer of a node is NULL i.e. if we reach the last element
  // we stop the while loop
  while ((*pntr_nxt).next != *head)
  {
    pntr_nxt = (*pntr_nxt).next;
  }
  // redirecting head to the second value
  struct node *pntr_temp = *head;
  pntr_nxt->next=(*head)->next;
  (*head) = (*(*head)).next;
  free(pntr_temp);
}
void print(struct node *head)
{
  struct node *pntr_nxt = head;
  do{
    printf("Age %d\nName %s\nAdress %s-->", (*pntr_nxt).age,pntr_nxt->name,pntr_nxt->adress);
    pntr_nxt = (*pntr_nxt).next;
  }
  while (pntr_nxt != head);
  printf("HEAD\n");
}
void senior(struct node *head){
    struct node *pntr_nxt = head;
    printf("Printing The data of nodes with age over 60\n");
    do{
        if((*pntr_nxt).age>=60){
            printf("Age %d\nName %s\nAdress %s-->\n", (*pntr_nxt).age,pntr_nxt->name,pntr_nxt->adress);
        }
        pntr_nxt = (*pntr_nxt).next;
    }
    while (pntr_nxt != head);
    printf("HEAD\n");
}
int main(){
    int runner=1,menu;
    struct node *head;
    while(runner){
        printf("0.Exit\n");
        printf("1.Create a link list\n");
        printf("2.Input\n");
        printf("3.Delete\n");
        printf("4.Show\n");
        printf("5.Senior citizen\n");
        scanf("%d",&menu);
        int num,ind;
        char name[100],adress[100];
        switch(menu){
            case 0:
                runner=0;
                break;
            case 1:
                int init_val;
                printf("Enter  Age of first node ");
                scanf("%d",&init_val);
                printf("Enter  Name of first node ");
                scanf("%s",name);
                printf("Enter  Adress of first node ");
                scanf("%s",adress);
                initialize(&head,init_val,adress,name);
                break;
            case 2:
                printf("Enter  Age of first node ");
                scanf("%d",&num);
                printf("Enter  Name of first node ");
                scanf("%s",name);
                printf("Enter  Adress of first node ");
                scanf("%s",adress);
                enqueue(&head,num,adress,name);
                break;
            case 3:
                dequque(&head);
                break;
            case 4:
                print(head);
                break;
            case 5:
                senior(head);
                break;
        }
    }
}