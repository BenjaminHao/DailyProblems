# Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

## **Thinking**
First of all, what kinds of characters in the string? Are they ASCII code, or just 26 normal English characters. We have different solutions for different situations.

If they are ASCII code, we can have an array of 256 booleans and set them all false. We iterate the characters. If the value of boolean is true, then the character has already been existed. If the value of boolean is false, we set it to be true.
```cpp
bool isUnique(std::string s)
{
    bool a[256];
    memset(a, false, sizeof(a));

    for (int i = 0; i < s.size(); ++i)
    {
        int index = (int)s[i];
        if (a[index]) return false;
        a[index] = true;
    }

    return true;
}
```
> The time complexity is O(n).
### **Bit manipulation**
 We can also use bit manipulation to reduce the space we used.  
For ASCII code, we need 256 bits, i.e. An array that has 8 ints. The key here is to get the character into the correct bit. For example, we have character 'b', the corresponding ASCII code is 98. Then, 98/32 is the corresponding index of array, and 98%32 is the corresponding bit.
```cpp
bool inUnique(std::string s)
{
    int a[8]; // int - 32 bits
    memset(a, 0, sizeof(a));
    
    for (int i = 0; i < s.size(); ++i)
    {
        int code = (int)s[i];
        int index = code/32, bit = code%32; // get correct position
        if (a[index] & (1 << bit)) return false; // & - bitwise AND, << - left shift
        a[index] |= (1 << bit); // | - bitwise inclusive OR
    }
    return true;
}
```
| a | b | a & b | a \| b | a ^ b |
|:--:|:--:|:----:|:----:|:----:|
|0|1|0|0|1|
|0|1|0|1|1|
|1|0|0|1|1|
|1|1|1|1|0|
> bitwise operation

If the characters are only a - z, then it's eaiser.
```cpp
bool isUnique(std::string s)
{
    int check = 0;
    
    for (int i = 0; i < s.size(); ++i
    {
        int code = (int)(s[i] - 'a');
        if (check & (a << code)) return false;
        check |= (1 << code);
    }

    return true;
}

```
