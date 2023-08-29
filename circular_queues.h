/*
Implementation of Circular Queue Data Structure.
typedef struct QUEUE
{
    int *array;
    int rear, front, size, max_size;
}QUEUE;
Methods:
1. init_queue(): Initialize queue, set rear = top = -1.
2. enQueue(): Enqueue the specified element (return 0: success || INT_MIN: queue overflow).
3. deQueue(): Dequeue the front element (return element: success || INT_MIN: queue underflow).
4. show_queue(): Print queue to console from front to rear.
*/

#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -9999

typedef struct QUEUE
{
    int *array;
    int rear, front, size, max_size;
}QUEUE;

QUEUE* init_queue(int max_size);
int enQueue(QUEUE* q, int elem);
int deQueue(QUEUE* q);
void show_queue(QUEUE *q);

QUEUE* init_queue(int max_size)
{
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    if (q==NULL)
    {
        free(q);
        return NULL;
    }
    q->array = (int*)malloc(sizeof(int)*max_size);
    if (q->array==NULL)
    {
        free(q->array);
        free(q);
        return NULL;
    }
    q->max_size = max_size;
    q->front = -1; 
    q->rear = -1;
    q->size = 0;
    return q;
}
int enQueue(QUEUE *q, int elem)
{
    if (q->size==q->max_size)  // Queue overflow
        return INT_MIN;
    if ((q->rear==q->front)&&(q->rear==-1))
    {
        q->rear = 0;
        q->front = 0;
    }
    else
        q->rear = (q->rear + 1)%(q->max_size);
    q->array[q->rear] = elem;
    q->size += 1;
    return 0;
}
int deQueue(QUEUE *q)
{
    if (q->front==-1)  // Queue underflow
        return INT_MIN;
    int temp = *(q->array + q->front);
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1)%(q->max_size);  // Current front becomes
                                                  // irrelevant
    }
    q->size -= 1;
    return temp;
}
void show_queue(QUEUE *q)
{
    int i, x, y;
        printf("\t\t----------- QUEUE Elements: -----------\n");
    if ((q->rear==q->front)&&(q->rear==-1))
    {
        printf("\t\t\t   QUEUE UNDERFLOW!\n");
        printf("\t\t---------------------------------------\n");
        return;
    }
    if (q->front == q->rear) {
        printf("\t\t\t  Index %d: %d  <-- front, rear\n", q->front, q->array[q->front]);
        printf("\t\t---------------------------------------\n");
        return;
    }
    x = (q->front>q->rear)?q->front:q->rear;
    y = (q->front<q->rear)?q->front:q->rear;
    for (i = y; i <= x; i++)
    {
        if (i==q->front)
            printf("\t\t\t  Index %d: %d  <-- front\n", i, q->array[i]);
        else if (i==q->rear)
            printf("\t\t\t  Index %d: %d  <-- rear\n", i, q->array[i]);
        else
            printf("\t\t\t  Index %d: %d\n", i, q->array[i]);
    }
    printf("\t\t---------------------------------------\n");
}