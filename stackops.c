#include<stdio.h>
int stack[100], choice, n, top, x, i;
void push();
void pop();
void display();
int main(){
    top = -1;
    printf("Enter the size of Stack[MAX=100]: ");
    scanf("%d", &n);
    printf("Stack operations using array: \n");
    printf("------------------------------ \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    do
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("EXIT POINT");
                break;
            }
            default:
                printf("Please enter a valid choice (1/2/3/4)");
        }
    } while (choice!=4);
    return 0;
}
void push()
{
    if (top>=n-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    } 
}
void pop()
{
    if (top<=-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = stack[top];
        top--;
        printf("The popped element is %d\n", x);
    }
}
void display()
{
    if (top>=0)
    {
        printf("The stack elements are: \n");
        for (int i=top; i>=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
}