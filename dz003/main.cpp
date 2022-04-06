#include <iostream>
#include <string>
#include <fstream>
#include "queue.h"

using namespace std;

char* str_trim(char* str)
{
    char* str_copy = str;
    while (*str_copy == ' ') str_copy++;
    int size = strlen(str_copy);

    char* trimmed = new char[size];

    for (size_t i = 0; i < size + 1; i++)
    {
        trimmed[i] = str_copy[i];

        if (!*str_copy)
            break;
    }

    int trimmed_size = strlen(trimmed);
    int i = 0;
    while (trimmed[trimmed_size - 1 - i] == ' ')
    {
        trimmed[trimmed_size - 1 - i] = 0;
        i++;
    }

    return trimmed;
}

bool read_file(const char* filename, Queue*& credits, Queue*& deposits)
{
    ifstream f(filename);
    
    if (!f.is_open())
    {
        cout << "File reading error" << endl;
        return false;
    }

    while (!f.eof())
    {
        int buf_size = 256;
        char* line = new char[buf_size];
        f.getline(line, buf_size - 1);

        if (f.fail())
        {
            f.clear();
            continue;
        }

        char* line_copy = new char[buf_size];
        strcpy_s(line_copy, buf_size, line);
        char* context;
        man m;
        int i = 0;

        while (char* part = strtok_s(line_copy, "|", &context))
        {
            if (i == 0)
                m.name = str_trim(part);
            else if (i == 1)
                m.sex = str_trim(part);
            else if (i == 2)
                m.age = stoi(str_trim(part));
            else if (i == 3)
                m.work = str_trim(part);
            else if (i == 4)
                m.income = stoi(str_trim(part));
            else if (i == 5)
            {
                m.purpose = str_trim(part);

                if (strcmp(m.purpose, "кредит"))
                    enqueue(credits, m);
                else
                    enqueue(deposits, m);
            }

            i++;
            line_copy = nullptr;
        }
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Queue* credits = new Queue;
    Queue* deposits = new Queue;

    read_file("data.txt", credits, deposits);

    cout << "Кредиты: " << endl;
    ShowQueue(credits);
    cout << endl << "Вклады: " << endl;
    ShowQueue(deposits);
}