#include"tree.c"
int main(){
    struct tree *root;
    int menu,runner=1;
    while(runner){
        printf("0.Exit\n");
        printf("1.Create a Tree\n");
        printf("2.Insert a leaf \n");
        printf("3.Delete a leaf \n");
        printf("4.Inorder\n");
        printf("5.Postorder\n");
        printf("6.Preorder\n");
        printf("7.Search\n");
        printf("8.Inorder Succesor\n");
        printf("9.Height\n");
        printf("10.Minimun Element\n");
        printf("11.only Right Child Element\n");
        printf("12.only leaf and non-leaf Element\n");
        scanf("%d",&menu);
        int val;
        switch (menu)
        {
        case 0:
            runner=0;
            break;
        case 1:
            printf("Enter the initial value: ");
            scanf("%d",&val);
            initialize(&root,val);
            break;
        case 2:
            printf("Enter the  value: ");
            scanf("%d",&val);
            addnode(root,val);
            break;
        case 3:
            printf("Enter the value to be deleted: ");
            scanf("%d",&val);
            deletion(root,val);
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        case 6:
            preorder(root);
            printf("\n");
            break;
        case 7:
            printf("Enter the value to be searched: ");
            scanf("%d",&val);
            if(search(root,val)){
                printf("ELEMENT FOUND");
                break;
            }
            printf("ELEMENT NOT FOUND");
            break;
        case 8:
            printf("Enter the value of node: ");
            scanf("%d",&val);
            printf("The inorder succesor of %d is %d\n",val,inorder_suceesor_byval(root,val));
            break;
        case 9:
            printf("The depth of tree is %d\n",depth(root));
            break;
        case 10:
            printf("The minimum element of tree is %d\n",min_element(root));
            break;
        case 11:
            printf("The no of  element of tree with only right child is %d\n",onlyright(root));
            break;
        case 12:
            printf("The no of  leaf element of tree is %d\n",leaf(root));
            printf("The no of  non-leaf element of tree is %d\n",notleaf(root));
            break;
        default:
            break;
        }
    }

}