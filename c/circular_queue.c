#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue_circular() {
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    rear -> next = p;
    scanf("%d", &p->data);
    p -> next = front;
    rear = p;
}

void dequeue_circular() {
    struct node *p;
    p = front;
    front = front -> next;
    rear -> next = front;
    free(p);
}

struct node *create_circular_queue() {
    struct node *p = NULL;
    int n;
    printf("\nEnter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    if(front == NULL && rear == NULL) {
        front = (struct node*)malloc(sizeof(struct node));
        p = front;
        rear = front;
        scanf("%d", &(p -> data));
        rear -> next = front;
    }
    for (int i = 1; i < n; i++) {
        enqueue_circular();
    }
    return front;
}

void display_circular_queue() {
    struct node *p;
    int count = 0;
    p = front;
    while(p -> next != front) {
        printf("Node %d: %d\n", count, p -> data);
        p = p -> next;
        count++;
    }
    printf("Node %d: %d\t", count, p -> data);
}

int main() {

    struct node *front = NULL;
    front = create_circular_queue();
    display_circular_queue(front);
    printf("\nEnter data to enqueue: ");
    enqueue_circular();
    display_circular_queue();
    dequeue_circular();
    printf("\nCircular Queue after deletion\n");
    display_circular_queue();
   
    return 0;
}
