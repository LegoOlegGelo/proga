#pragma once
struct Stack;

void push(Stack*& stack, char val);
bool pop(Stack*& stack, char& val);
bool peek(Stack* stack, char& val);
void print(Stack*& stack);