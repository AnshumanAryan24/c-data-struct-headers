/*
Singly Linked-Lists Header File
struct ListNode {
    int data;
    struct ListNode *next;
};
Methods:
1. void init_link_list(struct ListNode**): Initialize linked-list
2. void insertAtBeg(struct ListNode**, int): Insert at beginning of list (put element before current start)
3. void insertAtLast(struct ListNode**, int): Insert at end of list (put element after current last)
4. void insertAtPosition(struct ListNode**, int, int): Insert at k-th position (1-indexed)
5. void insertAfterKey(struct ListNode**, int, int): Insert immediately after the first occurence of value, if found
6. void printList(struct ListNode*): Print linked-list to console

7. int delFromBeg(struct ListNode**): Delete first element and reassign head pointer
8. int delFromLast(struct ListNode**): Delete current last element
9. int delFromPosition(struct ListNode**, int): Delete element present at k-th index (1-indexed)

10. void rev_link_list(struct ListNode**): Reverse linked-list and reassign head pointer
*/

#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -9999

struct ListNode {
    int data;
    struct ListNode *next;
};

void init_link_list(struct ListNode**);
void insertAtBeg(struct ListNode**, int);
void insertAtLast(struct ListNode**, int);
void insertAtPosition(struct ListNode**, int, int);
void insertAfterKey(struct ListNode**, int, int);
void printList(struct ListNode*);

int delFromBeg(struct ListNode**);
int delFromLast(struct ListNode**);
int delFromPosition(struct ListNode**, int);

void rev_link_list(struct ListNode**);

void init_link_list(struct ListNode **head){
    (*head) = NULL;
}

void insertAtBeg(struct ListNode **head, int x) {
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = x;
    if ((*head) == NULL) {
        (*head) = new_node;
        new_node->next = NULL;
        return;
    }
    
    // else
    new_node->next = (*head);
    (*head) = new_node;
}

void insertAtLast(struct ListNode **head, int x) {
    struct ListNode *temp, *new_node;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = x;
    new_node->next = NULL;
    if ((*head) == NULL) {
        (*head) = new_node;
        return;
    }
    
    // else
    temp = (*head);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPosition(struct ListNode **head, int x, int k) {
    struct ListNode *temp, *new_node;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = x;
    if ((*head) == NULL) {
        return;
    }
    else if (k == 1) {
        new_node->next = (*head);
        (*head) = new_node;
        return;
    }
    
    temp = (*head);
    while(((--k)!=0) && (temp != NULL)) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertAfterKey(struct ListNode **head, int x, int key) {
    struct ListNode *temp, *new_node;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = x;

    if ((*head) == NULL) {
        return;
    }
    else if ((*head)->data == key) {
        new_node->next = (*head)->next;
        (*head)->next = new_node;
    }

    temp = (*head);
    while ((temp->data != key) && (temp != NULL)) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void printList(struct ListNode *head) {
    struct ListNode *temp;
    temp = head;
    if (temp == NULL) {
        return;
    }
    while (temp->next != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int delFromBeg(struct ListNode **head) {
    int x;
    struct ListNode *temp;
    if ((*head) == NULL) {
        return INT_MIN;
    }
    
    if ((*head)->next == NULL) {
        temp = (*head);
        x = temp->data;
        free(temp);
        (*head) = NULL;
        return x;
    }
    
    // else
    temp = (*head);
    x = temp->data;
    (*head) = (*head)->next;
    free(temp);
    return x;
}

int delFromLast(struct ListNode **head) {
    int x;
    struct ListNode *temp, *prev;
    if ((*head) == NULL) {
        return INT_MIN;
    }
    if ((*head)->next == NULL) {
        temp = (*head);
        x = temp->data;
        (*head) = NULL;
        free(temp);
        return x;
    }
    
    // else
    temp = (*head);
    prev = temp;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    x = temp->data;
    free(temp);
    prev->next = NULL;
    return x;
}

int delFromPosition(struct ListNode **head, int k) {
    struct ListNode *temp, *prev;
    int x;
    temp = (*head);
    prev = temp;

    if ((*head)==NULL) {
        return INT_MIN;
    }
    if (k==1) {
        return delFromBeg(head);
    }
    
    //else
    while ((--k)!=0 && temp!=NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (temp==NULL) {
        return INT_MIN;
    }
    x = temp->data;
    prev->next = temp->next;
    free(temp);
    return x;
}

void rev_link_list(struct ListNode **head) {
    struct ListNode *prev, *temp, *next;

    if ((*head)==NULL || (*head)->next==NULL)
        return;
    
    prev = NULL;
    temp = (*head);
    while (temp!=NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    (*head) = prev;
}