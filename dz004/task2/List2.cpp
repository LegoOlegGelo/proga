#include <iostream>
#include "List2.h"

#define BIL 1000000000

void create_if_not_exists(elem*& cur)
{
	if (!cur)
	{
		cur = new elem;
		cur->a = 0;
	}
}

void add_to_num(elem*& num1, elem* n2)
{
	create_if_not_exists(num1);

	elem* cur = num1;
	elem* addend = n2;
	elem* prev = nullptr;

	int num2 = 0;

	while (addend || num2 != 0)
	{
		create_if_not_exists(cur);

		if (addend)
		{
			num2 += addend->a;
			addend = addend->next;
		}

		int s = cur->a + num2;
		cur->a = s % BIL;
		num2 = s / BIL;

		prev = cur;
		cur = cur->next;
		create_if_not_exists(cur);
		cur->prev = prev;
		prev->next = cur;
	}
}

void add_to_num(elem*& num1, int num2)
{
	create_if_not_exists(num1);

	elem* cur = num1;
	elem* prev = nullptr;

	while (num2 != 0)
	{
		create_if_not_exists(cur);

		int s = cur->a + num2;
		cur->a = s % BIL;
		num2 = s / BIL;

		prev = cur;
		cur = cur->next;
		create_if_not_exists(cur);
		cur->prev = prev;
		prev->next = cur;
	}
}

int digits_count(int x)
{
	int count = 0;

	while (x > 0)
	{
		count++;
		x /= 10;
	}

	return count;
}

void show_num(elem* num)
{
	create_if_not_exists(num);

	elem* cur = num;

	while (cur)
		if (!cur->next) break;
		else cur = cur->next;

	while (cur)
	{
		if (cur->a != 0)
		{
			if (cur->next)
				if (cur->next->a != 0)
					for (size_t i = 0; i < 9 - digits_count(cur->a); i++)
						std::cout << 0;

			std::cout << cur->a;
		}

		cur = cur->prev;
	}

	std::cout << std::endl;
}