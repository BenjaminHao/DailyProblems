# Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

## FOLLOW UP
Write the test cases for this method.

## Thinking
The question is removing duplicate characters in place. Need to make sure that *an extra copy of the array* means we cannot use any array, or we can use an array that has nothing to do with the string.

If we cannot use any arrays and only able to use couple of variables, we can iterate the string. Each time we iterate an element, we remove the same elements from this element till the end(for example, set it '\0'), the time complexity is O(n^2).
```cpp
void removeDuplicate(char s[])
{
    if (s.size() < 2) return; // empty string or string with 1 character
    int p = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != '\0')
        {
            s[p] = s[i];
            ++p;

            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[j] == s[i])
                    s[j] = '\0';
            }
        }
    }
    s[p] = '\0';
}
```
If we can use arrays that unrelated with the string, then we can create an array for the characters that showed up. We only need to iterate the string once. The time complexity is O(n)
```cpp
void removeDuplicate(char s[])
{
    if (s.size() < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (!c[s[i]])
        {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';
}
```
### Test cases
1. String without repeating characters, e.g., abcd
2. String that only has repeating characters, e.g., aaaa
3. Empty string
4. Contiguous repeating characters, e.g., aaabbb
5. Noncontiguous repeating characters, e.g., abababa

> see the program for more details