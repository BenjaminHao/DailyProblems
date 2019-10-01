# Question 1.2
## Write code to reverse a C-Style String
## C-String means that 'abcd' is represented as five characters, including the null character.

## **Thinking**
This question is to test if you pay attention to the null character in C-Style String.  
Here is the code:

```cpp
void swap(char& a, char& b)
{
    // XOR swap algorightm
    a = a^b;
    b = a^b;
    a = a^b;
}

void reverse1(char* s)
{
    if (!s) return; // if s is null pointer, return

    char* p = s, *q = s; // two pointers
    
    while (*q) ++q; // move q to the null character
    --q; // move q back one bit, to point at the last character

    while (p < q)
        swap(*p++, *q--); // swap two characters and move respectively
}

void reverse2(char* s)
{
    int n = strlen(s); // n is the length of c-string s

    for (int i = 0; i < n / 2; ++i) // iterate first half of c-string
        swap(s[i], s[n - i - 1]); // swap corresponding characters
}
```

### XOR Swap Algorithm
XOR swap can swap values of distinct variables having the same data type without using a temporary variable. "Distinct" means that the variables are stored at different, non-overlapping, memory addresses as the algorithm would set a single aliased value to zero; the actual values of the variables do not have to be different.

What is ^ operation?  
0 ^ 0 = 0    
0 ^ 1 = 1  
1 ^ 0 = 1  
1 ^ 1 = 0  
If they are the same, the result is 0, 1 if not same.

Assuming:  
`a = 10`, i.e. *1010* in binary  
`b = 12`, i.e. *1100* in binary  
If swapping `a` and `b`, in the point of view of binary, because the first and last bits are the same, we only need to swap the two bits in the middle.  
How to swap? Because there are only 0 and 1 in binary, we only need to change 0 to 1, and change 1 to 0.
In conclusion, **to swap two numbers, we only need to change the the non-overlapping(i.e. different) bits.**  
And if the length of the binary are different, we need to add *0*'s before the short one.

**First: `a = a ^ b`**  
The result is *0110*, i.e., *110*. `a` now is actually *different value*. It is the non-overlapping bits. 1 represents different, 0 represents the same. *110* stands for `a` and `b` have differnet values at the two bits in the middle.  
**Second, `b = a ^ b`**  
Now `a` is *different value*, `b` is still the original number, how does `b` become the original value of `a`?  
We can try to understand XOR operation in a different way:  
if the left number is 0, the result is the same with the right number  
if the left number is 1, the result is the reverse of the right number  
So `a ^ b` means:  
The bit number of `a` is 0, then the original `a` and `b` have the same bit numbers, then `b` doesn't change  
The bit number of `a` is 1, then the original `a` and `b` have different numbers, then the bit number of `b` need to be reversed  
So the original `b` is *1100*. The first and the last bits are the same. Reverse the two bits in the middle. The result is *1010*.
**Third, `a = a ^ b`**  
Now `a` is still the *different value*, `b` has the value of the original `a`. Then just like the second step, the result is the original `b`.