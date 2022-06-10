#include "stack.c"
int main(){
    Stack s1;
    initialize(&s1);
    random(&s1,55);
    print(&s1);
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    print(&s1);
}
