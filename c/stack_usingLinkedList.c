#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *push()
{
    node *top, *p;
    int n;
    top = (node *)malloc(sizeof(node));
    top->next = NULL;

    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the data for node -1 : ");
    scanf("%d", &top->data);
    for (int i = 2; i <= n; i++)
    {
        p = (node *)malloc(sizeof(node));
        printf("Enter the data for node -%d : ", i);
        scanf("%d", &p->data);
        p->next = top;
        top = p;
    }

    return top;
}

void popAll(node *top)
{
    node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

node *insert(node *top)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    printf("\nEnter the data for  inserting node : ");
    scanf("%d", &p->data);
    p->next = top;
    top = p;
    return top;
}

node *delete (node *top)
{

    node *temp;
    temp = top;
    top = top->next;
    free(temp);

    return top;
}

int main()
{
    node *top = push();
    node *top1 = insert(top);
    printf("Stack elements after insertion is : \n");
    popAll(top1);
    node *top2 = delete (top1);
    printf("Stack elements after deletion is : \n");
    popAll(top2);

    return 0;
}
