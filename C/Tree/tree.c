#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};
struct queue{
    struct tree *data;
    struct queue* next;
};
struct queue *inorder_storage;
void push(struct queue **head, struct tree *pntr_tree){
    if((*head)==NULL){
        (*head)=(struct queue*)malloc(sizeof(struct queue));
        (*head)->data=pntr_tree;
        (*head)->next=NULL;
        return;  
    }
    struct queue *new_node,*trav=(*head);
    new_node=(struct queue*)malloc(sizeof(struct queue));
    new_node->data=pntr_tree;
    new_node->next=NULL;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=new_node;
}
void pop(struct queue **head){
    if((*head)==NULL){
        return;  
    }
    struct queue *output;
    output=(*head);
    (*head)=(*head)->next;
    // free(output);
}
struct tree* front(struct queue **head){
    if((*head)==NULL){
        return NULL;  
    }
    return (*head)->data;
}
int isempty(struct queue **head){
    if((*head)==NULL){
        return 1;  
    }
    return 0;
}
void initialize(struct tree**root,int val){
    (*root)=(struct tree*)malloc(sizeof(struct tree));
    (*root)->data=val;
    (*root)->left=NULL;
    (*root)->right=NULL;
}
void addnode(struct tree *root,int val){
    if(val>root->data){
        if(root->right!=NULL){
            addnode(root->right,val);
            return;
        }
        struct tree* new_node;
        new_node=(struct tree*)malloc(sizeof(struct tree));
        new_node->data=val;
        new_node->left=NULL;
        new_node->right=NULL;
        root->right=new_node;
        return;
    }
    if(root->left!=NULL){
        addnode(root->left,val);
        return;
    }
    struct tree *new_node;
    new_node=(struct tree*)malloc(sizeof(struct tree));
    new_node->data=val;
    new_node->left=NULL;
    new_node->right=NULL;
    root->left=new_node;
    return;
}
void inorder(struct tree *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
struct tree* search(struct tree *root,int query){
    if(root==NULL){
        return 0;
    }
    if(query>root->data){
        return search(root->right,query);
    }
    if(query<root->data){
        return search(root->left,query);
    }
    return root;
}
void preorder(struct tree *root){
    if(root==NULL){
        return;
    }
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct tree *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}
void inorder_store(struct tree*root){
    if(root==NULL){
        return ;
    }
    inorder_store(root->left);
    push(&inorder_storage,root);
    inorder_store(root->right);
}
int inorder_suceesor_byval(struct tree *root,int val){
    inorder_store(root);
    struct queue* pntr;
    pntr=inorder_storage;
    while (pntr!=NULL){
        if(pntr->data->data==val && pntr->next!=NULL){
            return pntr->next->data->data;
        }
        pntr=pntr->next;
    }
    return -1;
}
void queue_print(){
    struct queue* pntr;
    pntr=inorder_storage;
    while (pntr!=NULL){
        printf("%d->",pntr->data->data);
        pntr=pntr->next;
    }
}
int maximum(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int depth(struct tree *root){
    if(root==NULL){
        return -1;
    }
    return maximum(depth(root->left),depth(root->right))+1;
}
void search2(struct tree** cur, int item, struct tree** parent)  {  
    while (*cur != NULL && (*cur)->data != item)  
    {  
        *parent = *cur;  
        if (item < (*cur)->data)  
            (*cur) = (*cur)->left;  
        else  
            (*cur) = (*cur)->right;  
    }  
}  
struct tree* findMinimum(struct tree* cur)  
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  
void deletion(struct tree* root,int query){
    struct tree* parent = NULL;  
    struct tree* cur = root;  
  
    search2(&cur,query,&parent);  
    if (cur == NULL)  
        return;  
  
    if (cur->left == NULL && cur->right == NULL)  
    {  
        if (cur != root)  
        {  
            if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        struct tree* succ  = findMinimum(cur->right);  
  
        int val = succ->data;  
  
        deletion(root, succ->data);  
  
        cur->data = val;  
    }  
  
    else  
    {  
        struct tree* child = (cur->left)? cur->left: cur->right;  
  
        if (cur != root)  
        {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
  
        else  
            root = child;  
        free(cur);  
    }  
}  
  
