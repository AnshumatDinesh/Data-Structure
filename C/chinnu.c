#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *name;
    struct node *next;
};
void initialize(struct node **head, char *name)
{
    *(head) = (struct node *)malloc(sizeof(struct node));
    char *name_cpy = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(name_cpy, name);
    (*(head))->next = *head;
    (*head)->name = name_cpy;
}
void enqueue(struct node **head, char *name)
{
    if ((*head) == NULL)
    {
        initialize(head, name);
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    char *name_cpy = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(name_cpy, name);
    new_node->name = name_cpy;
    new_node->next = *head;
    struct node *pntr_nxt = *head;
    while (pntr_nxt->next != *head)
    {
        pntr_nxt = pntr_nxt->next;
    }
    pntr_nxt->next = new_node;
}
void rem(struct node **head, struct node *nde_to_be_del)
{
    if ((*head) == NULL)
    {
        return;
    }

    struct node *pntr_nxt = *head;

    while ((*pntr_nxt).next != nde_to_be_del)
    {
        pntr_nxt = (*pntr_nxt).next;
    }
    pntr_nxt->next = (nde_to_be_del)->next;
    free(nde_to_be_del);
}
int eliminate(struct node **head,int people)
{
    if ((*head)->next == *(head))
    {
        printf("THE LAST TO BE REMOVED IS %s\n", (*head)->name);
        printf("GAME OVER\n");
        free((*head));
        return 0;
    }
    do
    {
        struct node *pntr_nxt = *head;
        int n=1;
        int initial_cnt=rand()%people;
        while (n<initial_cnt)
        {
            pntr_nxt = (*pntr_nxt).next;
            n++;
        }
        printf("THE PARTICIPANT DOING THE TASK IS %s AND THE RANDOM NO. WAS %d\n",pntr_nxt->name,initial_cnt);
        struct node * nxt_head=pntr_nxt->next;
        rem(head,pntr_nxt);
        *(head)=nxt_head;
        people--;
    }while((*head)->next!=(*head));
    eliminate(head,1);
}
void print(struct node *head)
{
    struct node *pntr_nxt = head;
    do
    {
        printf("Name %s\n", pntr_nxt->name);
        pntr_nxt = pntr_nxt->next;
    } while (pntr_nxt != head);
    printf("\n");
}

int main()
{
    printf("Enter the number of participants: ");
    int n;
    scanf("%d", &n);
    struct node *ll;
    char *name;
    printf("Enter name of %d th participant:", 1);
    scanf("%s", name);
    initialize(&ll, name);
    for (int i = 1; i < n; i++)
    {
        printf("Enter name of %d th participant:", i + 1);
        scanf("%s", name);
        enqueue(&ll, name);
    }
    printf("SO THE PARTICIPANTS AND THEIR CHOSES ARE:\n");
    print(ll);
    eliminate(&ll,n);
}