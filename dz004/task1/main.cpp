#include <iostream>
#include "List.h"

int main()
{
    elem* list = nullptr;

    add_unique(list, 1);
    add_unique(list, 2);
    add_unique(list, 3);
    add_unique(list, 2);

    show(list);
}