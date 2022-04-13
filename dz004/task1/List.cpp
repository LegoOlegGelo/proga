#include <iostream>
#include "List.h"

void add(elem*& first, int data)
{
    elem* newel = new elem;
    newel->a = data;

    if (first)
    {
        elem* curr = first;

        while (curr->next)
            curr = curr->next;

        curr->next = newel;
    }
    else
        first = newel;
}

void insert(elem*& first, int data, int pos)
{
    elem* newel = new elem;
    newel->a = data;

    if (first && pos > 0)
    {
        elem* curr = first;
        int p = 0;
        while (curr->next && p < pos - 1)
        {
            curr = curr->next;
            p++;
        }

        newel->next = curr->next;
        curr->next = newel;
    }
    else
    {
        newel->next = first;
        first = newel;
    }
}

const int* get(const elem* first, int pos)
{
    if (pos < 0 || !first) return nullptr;

    int p = 0;
    elem* curr = (elem*)first;
    while (curr && p < pos)
    {
        curr = curr->next;
        p++;
    }

    if (curr)
        return &curr->a;

    return nullptr;
}

int count(const elem* first)
{
    int cnt = 0;
    elem* curr = (elem*)first;
    while (curr)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

bool remove(elem*& first, int pos)
{
    if (pos < 0 || !first) return false;

    if (pos == 0)
    {
        elem* rem = first;
        first = first->next;
        delete rem;
        return true;
    }

    int p = 0;
    elem* curr = first;
    while (curr->next && p < pos - 1)
    {
        curr = curr->next;
        p++;
    }

    if (curr->next)
    {
        elem* rem = curr->next;
        curr->next = curr->next->next;
        delete rem;
        return true;
    }

    return false;
}

void clear(elem*& first)
{
    while (first)
    {
        elem* del = first;                 
        first = first->next;          
        delete del;
    }
}

void add_unique(elem*& list, int val)
{
    elem* cur = list;

    while (cur)
    {
        if (val == cur->a)
            return;

        cur = cur->next;
    }

    add(list, val);
}

void insert_unique(elem*& list, int data, int pos)
{
    elem* cur = list;

    while (cur)
    {
        if (data == cur->a)
            return;

        cur = cur->next;
    }

    insert(list, data, pos);
}

void show(elem* list)
{
    while (list)
    {
        std::cout << list->a << " ";

        list = list->next;
    }

    std::cout << std::endl;
}
