#include<stdio.h>
#include<stdlib.h>
// stack using an Array

struct ArrayStack
{
    int top;
    int capacity ;
    int *array;
};

struct ArrayStack* createStack (int cap)
{
struct ArrayStack *stack;
stack=(struct ArrayStack *) malloc(sizeof(struct ArrayStack));
stack->capacity=cap;
stack->top=-1;
stack->array=malloc(sizeof(int)*stack->capacity);
return(stack);
}

int isFull(struct ArrayStack *stack)
{
if (stack->top==stack->capacity-1)
{
return (1);
}
else{
return (0);
}
}
int isEmpty (struct ArrayStack *stack)
{
if (stack->top==-1)
{
    return (1);
}
else 
{
    return (0);
}
}
void push(struct ArrayStack *stack, int item)
{
if (!isFull(stack))
{
    stack->top++;
    stack->array[stack->top]=item;
}

}

int pop (struct ArrayStack *stack)
{
    int item;
    if(!isEmpty(stack))
    {
        item=stack->array[stack->top];
        stack->top--;
        return(item);
    }
    return (-1);

}


void main ()
{
int choice,item_value;
struct ArrayStack *stack;
stack=createStack(4);

while (1)
{
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Exit");
    printf("\n Enter your coice: ");

    scanf("%D", &choice);

    switch(choice)
    {
        case 1: printf("\n Emter a number: ");
                scanf("%d",&item_value);
                push(stack, item_value);
                break;
        case 2:
                item_value=pop(stack);
                if(item_value==-1)
                {
                printf("\n Stack is Empty. ");

                }
                else
                {
                printf("\n Poped value is: %d", item_value);
                }
                break;
        case 3: exit(0);
        default:
            printf("Invalid choice.");
            break;
    
    }


}



}