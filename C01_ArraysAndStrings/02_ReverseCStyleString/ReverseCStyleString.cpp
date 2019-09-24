#include <iostream>
#include <cstring>
#include <algorithm>

// see README for more interesting solutions.

void swap(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void reverse_OldSchool(char* s)
{
    if (s == nullptr) return;

    int left = 0, right = 0;

    while (s[right] != '\0') ++right;
    --right;

    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
}

void reverse(char* s)
{
    int n = strlen(s);

    for (int i = 0; i < n / 2; ++i)
    {
        swap(s[i], s[n - i - 1]);
    }
}

int main(){
    char s1[] = "1234567890";
    char s2[] = "1234567890";

    reverse_OldSchool(s1);
    reverse(s2);
    
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    return 0;
}