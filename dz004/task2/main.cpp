#include <iostream>
#include "List2.h"

int main()
{
    elem* num = nullptr;
    elem* num2 = nullptr;

    add_to_num(num, 12345);
    add_to_num(num, 1);
    add_to_num(num, 2000000000);
    show_num(num);

    add_to_num(num2, 999999999);
    add_to_num(num2, 999999999);
    add_to_num(num2, 999999999);
    show_num(num2);

    add_to_num(num, num2);
    show_num(num);
}