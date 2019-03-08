#include<stdio.h>
#include<stdlib.h>
#include"include/queue.h"

void push (Queue * queue, int item)
{
    Node * n = (Node *)malloc(sizeof(Node));
    n->item = item;
    n->next = NULL;

    if (queue->head == NULL) {
        queue->head = n;
    } 
    else {
        queue->tail = n;
    }
    queue->size++;
}
int pop (Queue * queue)
{
    // Get the first item
    Node * head = queue->head;

    int item = head->item;
    queue->head = head->next;
    queue->size--;
    free(head);
    return item;
}
int peek (Queue * queue)
{
    Node * head = queue->head;
    return head->item;
}
void display (Queue * queue)
{
    printf("\nDisplay: ");
    if (queue->size == 0)
        printf("No item in queue.\n");
    else {
        Node * head = queue->head;
        int i, size = queue->size;
        printf("%d item(s):\n", queue->size);

        for (i=0; i<size; i++) {
            if (i>0)
                printf(", ");
            printf("%d", head->item);
            head = head->next;
        }
    }
    printf("\n\n");
}
Queue createQueue () 
{
    Queue queue;
    queue.size    = 0;
    queue.head    = NULL;
    queue.tail    = NULL;
    queue.push    = &push;
    queue.pop     = &pop;
    queue.peek    = &peek;
    queue.display = &display;
    return queue;
}
int main () {
    Queue queue = createQueue();
    queue.display(&queue);

    printf("push item 2\n");
    queue.push(&queue, 2);    
    printf("push item 3\n");
    queue.push(&queue, 3);
    printf("push item 6\n");
    queue.push(&queue, 6);
    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));


    printf("peek item %d\n", queue.peek(&queue));
    queue.display(&queue);

    printf("pop item %d\n", queue.pop(&queue));
    printf("pop item %d\n", queue.pop(&queue));
    queue.display(&queue);

    printf("pop item %d\n", queue.pop(&queue));
    queue.display(&queue);
    printf("push item 6\n");
    queue.push(&queue, 6);

    queue.display(&queue);
    system("PAUSE");
}
