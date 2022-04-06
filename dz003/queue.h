#pragma once
#include <string>

struct man {
	char* name;
	char* sex;
	int age = -1;
	char* work;
	int income;
	char* purpose;
};


struct elem {
	man m;
	elem* next = nullptr;
};

struct Queue {
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t size = 0;
};

struct elem;

void enqueue(Queue*& queue, std::string name, int age);
void enqueue(Queue*& queue, man man);
bool dequeue(Queue*& queue, man& man);
void ShowQueue(Queue*& queue);
void clear(Queue*& queue);
