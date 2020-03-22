#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _Node{
    element data;
    struct _Node *next;
} Node;

typedef struct {
    Node *front, *rear;
}QueuePointer;

QueuePointer *createLinkedQueue(){
    QueuePointer *LQ = (QueuePointer*)malloc(sizeof(QueuePointer));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

void enQueue(QueuePointer *LQ, element item){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    if(LQ->front == NULL){
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else{
        LQ->rear->next = newNode;
        LQ->rear = newNode;
    }
}

int	isEmpty(QueuePointer *LQ)
{
	return (!(LQ->rear));
}

element deQueue(QueuePointer *LQ){
    Node *old = LQ->front;
    element item;
    if (isEmpty(LQ)) return 0;
    else{
        item = old->data;
        LQ->front = LQ->front->next;
        if(LQ->front == NULL)
            LQ->rear = NULL;
        free(old);
        return item;
    }
}

int main()
{
	QueuePointer *LQ = createLinkedQueue();
    enQueue(LQ, 1);
    enQueue(LQ, 2);
    enQueue(LQ, 3);
    printf("%d\n",deQueue(LQ));
    printf("%d\n",deQueue(LQ));
    printf("%d\n",deQueue(LQ));
    printf("%d\n",deQueue(LQ));
    return 0;
}
