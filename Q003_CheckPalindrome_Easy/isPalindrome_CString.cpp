/** isPanlindrome(char* str, int N)
 *  1. The size of string is N
 *  2. Initialize begin and end indices as 0 and N-1 respectively
 *  3. While begin index is smaller than end index
 *      a. return false if str[begin] != str[end]
 *      b. increment begin and decrement righ
 *  4. If reach here, then str is a panlindrome
**/
bool isPanlindrome(char str[])
{
    int begin = 0, end = 0;

    while (str[end] != '\0') ++end;
    --end;

    while (begin < end)
    {
        if (str[begin++] != str[end--])
        {
            return false;
        }
    }
    return true;
}