#include <iostream>
#include "stack.h"

struct Stack
{
    char b;
    Stack* next;
};

void push(Stack*& stack, char val)
{
    Stack* newel = new Stack;
    newel->b = val;
    newel->next = stack;
    stack = newel;
}

bool pop(Stack*& stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->b;
    stack = stack->next;
    
    return true;
}

bool peek(Stack* stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->b;
}

void print(Stack*& stack)
{
    char val;
    while (pop(stack, val))
        std::cout << val << std::endl;
}