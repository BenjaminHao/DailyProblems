#include <cstring>
#include <iostream>

bool isUnique1(std::string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));

    for (int i = 0; i < s.size(); ++i)
    {
        int index = (int)s[i];
        if (a[index]) return false;
        a[index] = true;
    }
    return true;
}

bool isUnique2(std::string s)
{
    int a[8];
    memset(a, 0, sizeof(a));

    for (int i = 0; i < s.size(); ++i)
    {
        int code = (int)s[i];
        int index = code / 32, bit = code % 32;
        if (a[index] & (1 << bit)) return false;
        a[index] |= (1 << bit);
    }

    return true;
}

int main()
{
    std::string s1 = "Hello World";
    std::string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
    std::cout << isUnique1(s1) << " " << isUnique1(s2) << std::endl;
    std::cout << isUnique2(s1) << " " << isUnique2(s2) << std::endl;
    return 0;
}
