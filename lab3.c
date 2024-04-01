#include<stdio.h>
#define DIM_MAX 100
int stack[DIM_MAX], top = -1, front = -1, rear = -1, queue[DIM_MAX];
void push(int elem)
{
    if(top == DIM_MAX - 1)
    {
        printf("STIVA E PLINA");
        return;
    }
    stack[++top] = elem;
}
void pop()
{
    if(top == -1)
    {
        printf("STIVA E GOALA");
        return;
    }
    top--;
}
void print()
{
    if(top == -1)
    {
        printf("STIVA E GOALA");
        return;
    }
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}
void enqueue(int elem)
{
    if(front == -1)
    {
        front = 0;
    }
    if(rear == DIM_MAX - 1)
    {
        printf("COADA ESTE PLINA");
        return;
    }
    queue[++rear] = elem;
}
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("COADA ESTE GOALA");
        return;
    }
    front++;
}
void print2()
{
    if(front == -1 || front > rear)
    {
        printf("COADA ESTE GOALA");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}
typedef struct
{
    char txt[DIM_MAX];
    int rand;
} Stack;
Stack stack3[DIM_MAX];
void push3(char sir[DIM_MAX], int r)
{
    if(top == DIM_MAX - 1)
    {
        printf("STIVA ESTE PLINA");
        return;
    }
    top++;
    stack3[top].rand = r;
    strcpy(stack3[top].txt, sir);
}
void undo()
{
    if(top == -1)
    {
        printf("STIVA ESTE GOALA");
        return;
    }
    top--;
}
void display3()
{
    for(int i = 0; i <= top; i++)
        printf("%s ", stack3[i].txt);
    printf("\n");
}
void ex3()
{
    char sir[DIM_MAX];
    int r = 1;
    while(scanf("%s", sir) == 1)
    {

        if(sir == "\n")
            r++;
        else
        {
            push3(sir,r);
        }
    }
    display3();
    undo();
    display3();
}
typedef struct
{
    int id;
    char txt[DIM_MAX];
} Queue;
Queue queue4[DIM_MAX];
void dequeue_4()
{
    if(front == -1 || front > rear)
    {
        printf("Coada este goala");
        return;
    }
    front++;
}
void display_4()
{
    for(int i = front; i <= rear; i++)
        printf("%d %s ", queue4[i].id, queue4[i].txt);
    printf("\n");
    }
void enqueue_4(char *sir, int numar)
{
    if(rear == DIM_MAX - 1)
    {
        printf("Coada e plina");
        return;
    }
    if(front == -1)
        front = 0;
    queue4[++rear].id = numar;
    strcpy(queue4[rear].txt, sir);
}
void ex4()
{
    char sir[DIM_MAX];
    int numar;
    while(scanf("%s %d", sir, &numar) == 2)
    {
        enqueue_4(sir,numar);
    }
    display_4();
    dequeue_4();
    display_4();
}
int main(void)
{
    ex4();
}
