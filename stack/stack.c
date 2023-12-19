#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *datas;
    int size;
    int length;
    void (*push)(struct Stack *stack, int data);
    int (*pop)(struct Stack *stack);
};
void push(struct Stack *stack, int data)
{
    if (stack->length < stack->size)
    {
        stack->datas[stack->length] = data;
        stack->length++;

        printf("Pushed: %d\n", data);
    }
    else
    {
        printf("Stack overflow. Cannot push %d.\n", data);
    }
}

int pop(struct Stack *stack)
{
    if (stack->length > 0)
    {
        stack->length--;
        int data = stack->datas[stack->length];

        printf("Popped: %d\n", data);

        return data;
    }
    else
    {
        printf("Stack underflow. Cannot pop.\n");
        return -1; 
    }
}

void initializeStack(struct Stack *stack, int size)
{
    stack->datas = (int *)malloc(size * sizeof(int));
    stack->size = size;
    stack->length = 0;
    stack->push = push;
    stack->pop = pop;
}


int main()
{
    struct Stack myStack;

    initializeStack(&myStack, 5);

    myStack.push(&myStack, 10);
    myStack.push(&myStack, 20);
    myStack.push(&myStack, 30);

    int poppedValue = myStack.pop(&myStack);
    printf("Popped value: %d\n", poppedValue);

    poppedValue = myStack.pop(&myStack);
    printf("Popped value: %d\n", poppedValue);

    free(myStack.datas); 

    return 0;
}
