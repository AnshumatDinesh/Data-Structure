#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *name;
    int number;
    struct node *next;
};
void initialize(struct node **head, int num, char *name)
{
    *(head) = (struct node *)malloc(sizeof(struct node));
    char *name_cpy = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(name_cpy, name);
    (*(head))->next = *head;
    (*(head))->number = num;
    (*head)->name = name_cpy;
}
void enqueue(struct node **head, int num, char *name)
{
    if ((*head) == NULL)
    {
        initialize(head, num, name);
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->number = num;
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
int eliminate(struct node **head, int initial_cnt)
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
        while (n<initial_cnt)
        {
            pntr_nxt = (*pntr_nxt).next;
            n++;
        }
        printf("THE PARTICIPANT TO BE ELIMINATED IS %s\n",pntr_nxt->name);
        int nxt_in_cnt=pntr_nxt->number;
        struct node * nxt_head=pntr_nxt->next;
        rem(head,pntr_nxt);
        *(head)=nxt_head;
        initial_cnt=nxt_in_cnt;
    }while((*head)->next!=(*head));
    eliminate(head,initial_cnt);
}
void print(struct node *head)
{
    struct node *pntr_nxt = head;
    do
    {
        printf("Name %s\tNumber chosen %d-->\n", pntr_nxt->name, pntr_nxt->number);
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
    int number;
    printf("Enter name of %d th participant:", 1);
    scanf("%s", name);
    printf("Enter choice  of %d th participant:", 1);
    scanf("%d", &number);
    initialize(&ll, number, name);
    for (int i = 1; i < n; i++)
    {
        printf("Enter name of %d th participant:", i + 1);
        scanf("%s", name);
        printf("Enter choice  of %d th participant:", i + 1);
        scanf("%d", &number);
        enqueue(&ll, number, name);
    }
    printf("SO THE PARTICIPANTS AND THEIR CHOSES ARE:\n");
    print(ll);
    int cnt;
    printf("ENTER THE INITIAL COUNT\n");
    scanf("%d",&cnt);
    eliminate(&ll,cnt);
}