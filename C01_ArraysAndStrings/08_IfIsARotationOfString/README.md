# Question 1.8
## Assume you have a method `isSubstring()` which checks if one word is a substring of another. Given two strings, `s1` and `s2`, write code to check if `s2` is a **rotation** of `s1` using **only one call** to `isSubstring()`
>“waterbottle” is a rotation of “erbottlewat”.  
Explain: "erbottle | wat" ---Rotate--> "wat | erbottle"

## Thinking
We cannot manipulate string `s1` and `s2` directly. Because they are not substring of each other at all.  
We can rotate string multiple times and call `isSubstring()` each time. But, the question tells us only use `isSubstring()` once. Besides, if we rotate string, we can just compare two strings with equivalent operator instead of using `isSubstring()`.

What can we do?  
We can change the original strings! How do we get into this step? If we want to check if string `a` is a substring of string `b`, normally, the string `b` is bigger(longer). Because, if they have the same length, we can just check if they are the same strings.  
We can consider extending the length of string `s1`, then call `isSubstring()` once to check if `s2` is the substring of the new `s1`. If yes, we can know `s2` is the rotation of `s1`.  
How can we extend the length of `s1`? We can do `s1 + s1` or `s1 + s2`. `s2` must be a substring of `s1 + s2`. So there's no point to do so. Then how about `s1 + s1`?
```
s1 + s1 = "waterbottlewaterbottle"
```
We can easily see, `s1 + s1` is actually the rotation of every single character. Meanwhile, the original characters are not changed.  
> For example, `"waterbottle"` rotates 2 characters clockwise. It becomes `"terbottlewa"`. But if we keep the original string the same. What we got would be `"waterbottlewa"`. And `"terbottlewa"` is the substring of `"waterbottlewa"` because `"waterbottlewa"` is just `"terbottlewa"` plus the original part. Thus, `s1 + s1` includes all the rotation of `s1`. So if `s2` is the substring of `s1 + s1`, then it must be the rotation of `s1`.

## Code
```cpp
bool isRotation(std::string s1, std::string s2)
{
    if (s1.size() != s2.size() || s1.size() <= 0)
        return false;
    return isSubstring(s1 + s1, s2);
}
```
This question is very easy as long as you get the direction.