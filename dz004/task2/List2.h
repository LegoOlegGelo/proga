#pragma once

struct elem
{
	int a;
	elem* next = nullptr;
	elem* prev = nullptr;
};


void add_to_num(elem*& num1, elem* num2);
void add_to_num(elem*& num1, int num2);
void show_num(elem* num);