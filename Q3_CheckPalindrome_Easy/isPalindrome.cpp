#include <string>

/** isPanlindrome(str)
 *  1. Find the length of str. Let length be n
 *  2. Initialize begin and end indices as 0 and n-1 respectively
 *  3. While begin index is smaller than end index
 *      a. return false if str[begin] != str[end]
 *      b. increment begin and decrement righ
 *  4. If reach here, then str is a panlindrome
**/
bool isPanlindrome(std::string str)
{
    int begin = 0, end = str.size() - 1;

    while (begin < end)
    {
        if (str[begin++] != str[end--])
        {
            return false;
        }
    }
    return true;
}