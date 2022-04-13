#pragma once

struct elem
{
    int a;
    elem* next = nullptr;
};

void add(elem*& list, int data);
void insert(elem*& first, int data, int pos);
const int* get(const elem* first, int pos);
int count(const elem* first);
bool remove(elem*& first, int pos);
void clear(elem*& first);

void add_unique(elem*& list, int val);
void show(elem* list);