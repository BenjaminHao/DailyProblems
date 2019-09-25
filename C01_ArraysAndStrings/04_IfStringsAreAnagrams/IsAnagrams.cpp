#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

bool isAnagrams1(std::string s1, std::string s2)
{
    if (s1.empty() || s2.empty()) return false;
    if (s1.size() != s2.size()) return false;

    // sort two strings, or write own O(nlogn) sorting algorithm.
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if (s1 != s2) return false;
    else return true;
}

bool isAnagrams2(std::string s1, std::string s2)
{
    if (s1.empty() || s2.empty()) return false;
    if (s1.size() != s2.size()) return false;

    // used for counting occurrences of each character
    int buffer[256];
    memset(buffer, 0, sizeof(buffer));

    for (int i = 0; i < s1.size(); ++i)
    {
        ++buffer[s1[i]];
        --buffer[s2[i]];
    }

    for (int i : buffer)
    {
        if (i != 0) return false;
    }

    return true;
}

int main()
{
    std::string s1 = "rare";
    std::string s2 = "rear";
    std::string s3 = "rate";

    if (isAnagrams1(s1, s2))
        std::cout << s1 << " and " << s2 << " are anagrams" << std::endl;
    else
        std::cout << s1 << " and " << s2 << " are not anagrams" << std::endl;

    if (isAnagrams2(s1, s3))
        std::cout << s1 << " and " << s3 << " are anagrams" << std::endl;
    else
        std::cout << s1 << " and " << s3 << " are not anagrams" << std::endl;
}