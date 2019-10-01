#include <iostream>
#include <cstring>

char* replace(char* s)
{
    // if null pointer, return nullptr
    if (s == nullptr) return nullptr;

    // if empty string, return nullptr
    int length = strlen(s);
    if (length == 0) return nullptr;

    // space counter
    int count = 0;
    for (int i = 0; i < length; ++i)
    {
        if (s[i] == ' ')
            ++count;
    }

    // create a new string. The size should be the size of s
    // plus 2 * space plus 1('\0').
    char *ns = new char[length + 2 * count + 1];
    // index(or pointer) for new string 
    int p = 0;
    for (int i = 0; i < length; ++i)
    {
        // if the character is space
        if (s[i] == ' ')
        {
            // replace space with '%20'
            ns[p] = '%';
            ns[p + 1] = '2';
            ns[p + 2] = '0';
            // move forword 3 
            p += 3;
        }
        // if not space
        else
        {
            // simply copy and move pointer
            ns[p] = s[i];
            ++p;
        }
    }
    // add '\0' at the end of new string
    ns[p] = '\0';
    return ns;
}

int main()
{
    char s[] = "Hello World ";
    std::cout << replace(s) << std::endl;

    return 0;
}