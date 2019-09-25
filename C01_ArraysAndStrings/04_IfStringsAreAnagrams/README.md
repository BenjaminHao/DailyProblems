# Write a method to decide if two strings are anagrams or not.

## Thinking
### What are anagrams?
Anagrams are two words that have the same characters, but in different positions. For example, *abbcd* an *abcdb* are a pair of anagrams.

### Method 1:
Because the characters of anagrams are the same, we can just sort them. After sorting, the two strings become the same.

```cpp
bool isAnagram(std::string s1, std::string s2)
{
    if (s1 == "" || s2 == "") return false;
    if (s1.size() != s2.size()) return false;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if (s1 == s2) return true;
    else return false;
}
```
> The time complexity of std::sort() is O(nlogn), then we use O(n) time to compair two strings.

### Method 2:
Because the characters of anagrams are the same, so we can just count the occurrences of every character in each string, then check if the occurrences of each character are the same. We need an array to save the occurrences.
```cpp
bool isAnagram(std::string s1, std::string s2)
{
    if (s1 == "" || s2 == "") return false;
    if (s1.size() != s2.size()) return false;

    int n = s1.size();
    int buffer[256];
    memset(buffer, 0, sizeof(buffer));

    for (int i = 0, i < n; ++i)
    {
        ++c[s1[i]];
        --c[s2[i]];
    }

    for (int i : buffer)
        if (i != 0)
            return false;
    
    return true;
}
```
> The time complexity is O(n).