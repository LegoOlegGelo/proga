// Односвязный список
// Реализация функций append, push, pop, find, print

#include <iostream>
#include <string>

using namespace std;

struct List
{
    List* next;
    int x;
};

void append(List* list, int x)
{
    if (list == nullptr)
    {
        list = new List;
        list->x = x;
        return;
    }

    while (list->next != nullptr)
        list = list->next;

    list->next = new List;
    list->next->x = x;
    list->next->next = nullptr;
}

void push(List*& list, int x, int index)
{
    if (list == nullptr)
        cout << "null" << endl;

    if (index == 0)
    {
        List* first = new List;
        first->x = x;
        first->next = list;
        list = first;
        return;
    }

    List* list_copy = list;

    while (list_copy->next != nullptr && --index > 0)
        list_copy = list_copy->next;

    if (index > 0)
    {
        cout << "index is out of range" << endl;
        return;
    }

    List* next_next = list_copy->next;
    list_copy->next = new List;
    list_copy->next->x = x;
    list_copy->next->next = next_next;
}

void pop(List*& list, int index)
{
    if (list == nullptr)
        cout << "null" << endl;

    if (index == 0)
        list = list->next;

    List* list_copy = list;

    while (list_copy->next != nullptr && --index > 0)
        list_copy = list_copy->next;

    if (index > 0)
    {
        cout << "index is out of range" << endl;
        return;
    }

    list_copy = list_copy->next;
}

void print_list(List* list, bool need_indexes = true)
{
    if (list == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }

    int i = 0;
    while (list != nullptr)
    {
        if (need_indexes) cout << i++ << ": ";

        cout << list->x << endl;
        list = list->next;
    }
}

int find_item(List* list, int num)
{
    if (list == nullptr)
    {
        cout << "NULL" << endl;
        return -1000;
    }

    int i = 0;

    while (list != nullptr)
    {
        if (list->x == num)
            return i;

        list = list->next;

        i++;
    }

    return -1; // не найден
}

int main()
{
    List* list = new List;
    list->x = 123;
    list->next = nullptr;

    append(list, 123);
    append(list, 123);
    append(list, 123);
    print_list(list);
    cout << endl;


    push(list, 0, 0);
    push(list, 444, 4);
    push(list, 111, 1);
    print_list(list);
    cout << endl;


    pop(list, 0);
    print_list(list);
    cout << endl;


    cout << "index of 123: " << find_item(list, 123) << endl;
    cout << "index of 444: " << find_item(list, 444) << endl;
    cout << "index of 9999999: " << find_item(list, 9999999) << endl;
}