#include <string>
#include <algorithm>

bool isPalindrome1(std::string s)
{
    std::string tmp = s;
    std::reverse(s.begin(), s.end());
    return tmp == s;
}

bool isPalindrome2(std::string s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}