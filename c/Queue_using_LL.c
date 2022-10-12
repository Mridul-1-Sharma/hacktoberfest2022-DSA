//Code for implementation of Queue using Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front,*back;

void enqueue(int num) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
     
    if (back == NULL) {
        front = back = temp;
    } else {
        back->next = temp;
        back = temp;
    }
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("\nQueue is Empty \n");
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        printf("\nRemoved Element : %d\n", temp->data);
        free(temp);
    }
}

void display() {
    struct node *temp = front;
  
    if ((front == NULL) && (back == NULL)) {
        printf("Queue is Empty\n");
        return;
    }
 
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL)
            printf("->");
    }
}

int main()
{
    int n,data;
    printf("Enter size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter data: ");
        scanf("%d",&data);
        enqueue(data);
    }
    display();
    dequeue();

    return 0;
}
