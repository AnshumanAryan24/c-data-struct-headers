/*
typedef struct STACK
{
    int max_size;
    int *A;
    int top;
}STACK;
Methods:
1. STACK* init_stack(int): Initialize stack
2. void push(STACK *s, int x): Push element on top of stack
3. int pop(STACK *s): Pop and return element from top of stack
4. void show_stack(STACK *s): Print stack to console
5. int get_top(STACK *s): Get value of top element without disturbing stack
*/

#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -9999

typedef struct STACK
{
    int max_size;
    int *A;
    int top;
}STACK;
STACK* init_stack(int);
void push(STACK *s, int x);
int pop(STACK *s);
void show_stack(STACK *s);
int get_top(STACK *s);

STACK* init_stack(int max_size)
{
    STACK *s;
    s = (STACK*)malloc(sizeof(STACK));
    if (s==NULL) {
        free(s);
        return(NULL);
    }
    s->A = (int*)malloc(sizeof(int)*max_size);
    if (s->A==NULL) {
        free(s->A);
        free(s);
        return(NULL);
    }
    s->top = -1;
    return s;
}
void push(STACK *s, int x)
{
    if (s->top == s->max_size-1) return;
    s->top += 1;
    s->A[s->top] = x;
}
int pop(STACK *s)
{
    int temp;
    if (s->top == -1) return INT_MIN;
    temp = s->A[s->top];
    s->top -= 1;
    return(temp);
}
void show_stack(STACK *s)
{
    int i;
    if (s->top == -1) {
        printf("OVERFLOW!!\n");
        return;
    }
    printf("\t\t---------------- STACK elements: ----------------\n");
    printf("\t\t\t\t\t%d  <--top\n", s->A[s->top]);
    for (i=s->top-1; i>=0; i--)
        printf("\t\t\t\t\t%d\n", s->A[s->top - i]);
    printf("\t\t-------------------------------------------------\n");
}
int get_top(STACK *s)
{
    if (s->top == -1) return INT_MIN;
    return(s->A[s->top]);
}