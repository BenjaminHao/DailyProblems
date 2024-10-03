#include <algorithm>
#include <string>

class solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        auto getLen = [&](int l, int r) {
            do { --l; ++r; } while(l >= 0 && r < s.length() && s[l] == s[r]);
            return r - l + 1;
        };

        int len = 0, start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int cur = std::max(getLen(i, i), getLen(i, i + 1));
            if (cur >  len)
            {
                len = cur;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, len);
    }
};
