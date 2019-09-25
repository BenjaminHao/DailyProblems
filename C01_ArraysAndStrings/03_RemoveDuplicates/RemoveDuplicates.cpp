#include <iostream>
#include <cstring>

// O(n^2)
void removeDuplicate1(char s[])
{
    // n is the size of the string
    int n = strlen(s);
    // if empty string or string with 1 char, return
    if (n < 2) return;
    // used as index in the modified string
    int index = 0; 
    
    // traverse through all characters
    for (int i = 0; i < n; ++i)
    {
        // check if the character is null character
        if (s[i] != '\0')
        {
            // if not, the modified string is the same with original one
            s[index] = s[i];
            ++index;

            // traverse all characters after the current one
            for (int j = i + 1; j < n; ++j)
            {
                // if theres any duplicates, set it to be null
                if (s[j] == s[i])
                {
                    s[j] = '\0';
                }
            }
        }
    }
    // set the last character of modified string to be null
    s[index] = '\0';
}

// O(n)
void removeDuplicate2(char s[])
{
    int n = strlen(s);
    if (n < 2) return;
    // used for checking if the character has existed
    bool buffer[256];
    memset(buffer, 0, sizeof(buffer));

    int index = 0;

    for (int i = 0; i < n; ++i)
    {
        // if the current character didn't exist before
        if (!buffer[s[i]])
        {
            // nothing changed
            s[index++] = s[i];
            // the character has already existed
            buffer[s[i]] = true;
        }
    }
    // set the last character of modified string to be null
    s[index] = '\0';
}

int main() 
{ 
    char s1[] = "abcde";
    char s2[] = "aaabbb";
    char s3[] = "";
    char s4[] = "abababc";
    char s5[] = "ccccc";
    removeDuplicate1(s1);
    removeDuplicate1(s2);
    removeDuplicate1(s3);
    removeDuplicate1(s4);
    removeDuplicate1(s5);
    std::cout<< s1 << " " << s2 << " " << s3
             << " " << s4 << " " << s5 << std::endl;
    return 0;
} 