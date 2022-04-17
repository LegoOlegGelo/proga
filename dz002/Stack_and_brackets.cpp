#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

const char* open_brackets = "([<{";
const char* close_brackets = ")]>}";

int get_open_bracket_index(char b)
{
    for (int i = 0; i < strlen(open_brackets); i++)
        if (open_brackets[i] == b)
            return i;
}

int is_bracket(char c)
{
    for (int i = 0; i < strlen(open_brackets); i++)
        if (open_brackets[i] == c)
            return i + 1;

    for (int i = 0; i < strlen(close_brackets); i++)
        if (close_brackets[i] == c)
            return -(i + 1);

    return 0;
}

int check_expression(const char* exp)
{
    Stack* brackets = nullptr;
    char val;
    int last_open_bracket = -1;

    for (size_t i = 0; i < strlen(exp); i++)
    {
        int b_type = is_bracket(exp[i]);

        if (b_type > 0) // open bracket
        {
            push(brackets, exp[i]);

			last_open_bracket = i;
        }

		else if (b_type < 0) // close bracket
		{
			if (pop(brackets, val))
			{
				if (close_brackets[get_open_bracket_index(val)] != exp[i])
					return i;
			}
			else
				return i;
		}
			
    }

    if (brackets != nullptr)
        return last_open_bracket;
    
    return -1;
}

int main()
{
    //const char* exp = "{(a(b)c[dae[123<4>]])}";
    const char* exp = "{()}";
    int res = check_expression(exp);
 
    if (res == -1)
        cout << "good expression" << endl;
    else
        cout << "bad expression: " << res << endl;

    return 0;
}