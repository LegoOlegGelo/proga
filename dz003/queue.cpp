#include <string>
#include <iostream>
#include "queue.h"

using namespace std;

man create_elem(char* name, int age)
{
	man m;
	m.age = age;
	m.name = name;
	return m;
}

void enqueue(Queue*& queue, char* name, int age)
{
	man m = create_elem(name, age);
	elem* newelem = new elem;
	newelem->m = m;

	if (queue->size == 0)
		queue->head = queue->tail = newelem;
	else
	{
		queue->tail->next = newelem;
		queue->tail = newelem;
	}

	queue->size++;
}

void enqueue(Queue*& queue, man m)
{
	elem* newelem = new elem;
	newelem->m = m;

	if (queue->size == 0)
		queue->head = queue->tail = newelem;
	else
	{
		queue->tail->next = newelem;
		queue->tail = newelem;
	}

	queue->size++;
}

bool dequeue(Queue*& queue, man& man)
{
	if (queue->size <= 0)
		return false;

	man = queue->head->m;
	elem* rem = queue->head;
	queue->head = queue->head->next;
	delete rem;
	queue->size--;

	return true;
}

void ShowQueue(Queue*& queue)
{
	man m;

	while (queue->size > 0)
	{
		dequeue(queue, m);
		cout << m.name << " (" << m.age << " лет): пол - " << m.sex 
			<< ", место работы - " << m.work 
			<< ", доход - " << m.income
			<< ", цель - " << m.purpose
			<< endl;
	}
}

void clear(Queue*& queue)
{
	while (queue->size > 0)
	{
		elem* rem = queue->head;
		queue->head = queue->head->next;
		delete rem;
		queue->size--;
	}
}