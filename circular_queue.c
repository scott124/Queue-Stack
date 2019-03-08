#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

char CircularQueue[MAX_SIZE];
int front = 0, rear = 0;

int isFull()
{
    return (((front+1) % MAX_SIZE) == rear );
}
int isEmpty()
{
    return (front == rear);
}
void Add(char * queue, char item)
{
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    printf("Add %c\n", item);
    CircularQueue[(front++)%MAX_SIZE] = item;
}
void Delete(char * queue)
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Delete %c\n", CircularQueue[(rear)%MAX_SIZE]);
    CircularQueue[rear++%MAX_SIZE] = ' ';
}
void printqueue(char * queue)
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i=rear; i%MAX_SIZE != front%MAX_SIZE; i++ ) 
        printf("%c ", queue[i%MAX_SIZE]);
    printf("\n");
}

int main(void)
{
    Add(CircularQueue, '1');
    printqueue(CircularQueue);
	Add(CircularQueue, '2');
    printqueue(CircularQueue);
	Add(CircularQueue, '3');
    printqueue(CircularQueue);
	Add(CircularQueue, '4');
    printqueue(CircularQueue);
    Delete(CircularQueue);
    printqueue(CircularQueue);
    Delete(CircularQueue);
    printqueue(CircularQueue);
    Delete(CircularQueue);
    printqueue(CircularQueue);
    printqueue(CircularQueue);
	Add(CircularQueue, '5');
    printqueue(CircularQueue);
	Add(CircularQueue, '5');
    printqueue(CircularQueue);
	Add(CircularQueue, '5');
    printqueue(CircularQueue);
	Add(CircularQueue, '4');
	Add(CircularQueue, '3');
    printqueue(CircularQueue);
	return 0;
}

