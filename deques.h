/*
Deque Data Structure Header File
typedef struct DEQUE {
    int *arr;
    int front, rear;
    int size, max_size;
}DEQUE;
Methods: 
1. DEQUE* init_deque(int): Initialize deque

2. void push_front(DEQUE*, int): Push element before current front
3. void push_rear(DEQUE*, int): Push element after current rear
4. int pop_front(DEQUE*): Pop and return element from the front
5. int pop_rear(DEQUE*): Pop and return element from the rear

5. void show_deque(DEQUE*): Print deque to console
*/

#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -9999

typedef struct DEQUE {
    int *arr;
    int front, rear;
    int size, max_size;
}DEQUE;

DEQUE* init_deque(int);

void push_front(DEQUE*, int);
void push_rear(DEQUE*, int);
int pop_front(DEQUE*);
int pop_rear(DEQUE*);

void show_deque(DEQUE*);

DEQUE* init_deque(int max_size) {
    DEQUE *dq = (DEQUE*)malloc(sizeof(DEQUE));
    if (dq==NULL) {
        free(dq);
        return NULL;
    }
    dq->arr = (int*)malloc(sizeof(int)*max_size);
    if (dq->arr==NULL) {
        free(dq->arr);
        free(dq);
        return NULL;
    }

    // else
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    dq->max_size = max_size;

    return dq;
}
void push_front(DEQUE *dq, int elem) {
    if (dq->front == 0) return;
    if (dq->front == dq->rear && dq->rear == -1) {
        dq->rear = ((dq->max_size)/2) - 1;
        dq->front = ((dq->max_size)/2) - 1;
    }
    else dq->front -= 1;

    dq->arr[dq->front] = elem;

    dq->size += 1;
}
void push_rear(DEQUE *dq, int elem) {
    if (dq->rear == dq->max_size-1) return;
    if ((dq->front == dq->rear) && (dq->rear == -1)) {
        dq->rear = ((dq->max_size)/2) - 1;
        dq->front = ((dq->max_size)/2) - 1;
    }
    else
        dq->rear += 1;

    dq->arr[dq->rear] = elem;

    dq->size += 1;
}
int pop_front(DEQUE *dq) {
    int x;
    if (dq->front == dq->rear) {
        if (dq->front == -1) {  // no element
            return INT_MIN;
        }
        else {  // single element
            x = dq->arr[dq->front];
            dq->front = -1;
            dq->rear = -1;
        }
    }
    else {
        x = dq->arr[dq->front];
        dq->front += 1;
    }

    dq->size -= 1;

    return x;
}
int pop_rear(DEQUE *dq) {
    int x;
    if (dq->front == dq->rear) {
        if (dq->rear == -1) {  // no element
            return INT_MIN;
        }
        else {  // single element
            x = dq->arr[dq->rear];
            dq->front = -1;
            dq->rear = -1;
        }
    }
    else {
        x = dq->arr[dq->rear];
        dq->rear -= 1;
    }

    dq->size -= 1;

    return x;
}

void show_deque(DEQUE *dq) {
    int i;
    if (dq->front == dq->rear && dq->front == -1) {
        printf("\n-----------------DEQUE UNDERFLOW!!------------------\n");
        return;
    }

    // else
    printf("\n------------------DEQUE ELEMENTS--------------------\n\n");
    printf("front-->");
    for (i=dq->front; i<dq->rear; i++)
        printf("%d, ", dq->arr[i]);
    printf("%d", dq->arr[dq->rear]);
    printf("<--rear\n");

    printf("\n----------------------------------------------------\n");
}