#include <string>
#include <algorithm>

bool isPalindrome(std::string s)
{
    std::string tmp = s;
    std::reverse(s.begin(), s.end());
    return tmp == s;
}