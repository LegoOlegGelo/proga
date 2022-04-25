#include <iostream>
#include <fstream>
#include "cgi_requests.h"

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

int recursive_call_count = 0;

void read_block(const char* filename, char* data = 0)
{
	recursive_call_count++;

	if (recursive_call_count > 1000)
	{
		cout << "1000th recursive call. Exit.";
		return;
	}

	ifstream f(filename);

	if (f.is_open())
	{
		auto sz = 65536;
		auto buf = new char[sz];

		while (!f.eof()) {
			f.getline(buf, sz);

			cout << endl;

			if (!strcmp(buf, "<!--###EXPRESSION2###-->"))
			{
				char* text = nullptr;
				get_param_value(text, "text", data);
				if (text)
				{
					int res = check_expression(text);

					if (res > -1)
					{
						for (size_t i = 0; i < res; i++)
							cout << text++[0];

						cout << "<b style=\"color: red;\">" << text++[0] << "</b>";
					}

					cout << text << endl;
				}
			}

			else if (!strcmp(buf, "<!--###EXPRESSION1###-->"))
			{
				char* text = nullptr;
				get_param_value(text, "text", data);
				if (text)
					cout << text;
			}

			else if (!strcmp(buf, "<!--###ANSWER###-->"))
			{
				char* text = nullptr;
				get_param_value(text, "text", data);
				if (text)
				{
					int res = check_expression(text);

					if (res == -1)
						cout << "<b style='color: green;'>good expression</b>" << endl;
					else
						cout << "<b style='color: red;'>bad expression: " << res << "</b>" << endl;
				}
			}

			else if (!strcmp(buf, "<!--###HEADER###-->"))
				read_block("blocks/header.php", data);

			else if (!strcmp(buf, "<!--###FOOTER###-->"))
				read_block("blocks/footer.php", data);

			else if (!strcmp(buf, "<!--###HEAD_META###-->"))
				read_block("blocks/head_meta.php", data);

			else if (!strcmp(buf, "<!--###TASKS_MENU###-->"))
				read_block("blocks/tasks_menu.php", data);

			else
				cout << buf;
		}

		delete[] buf;
	}
	else
		cout << "read error with " << filename << endl;

	f.close();
}

int main()
{
	cout << "Content-type: text/html; charset=Windows-1251\n\n";

	check_expression("(((");

	char* data = nullptr;
	get_form_data(data);

	recursive_call_count = 0;
	read_block("tasks/task2.html", data);

	return 0;
}