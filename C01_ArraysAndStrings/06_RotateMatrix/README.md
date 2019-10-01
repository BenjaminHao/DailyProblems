# Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

## Thinking
If we have an image
```
1   2   3   4
5   6   7   8 
9   10  11  12 
13  14  15  16
```
After rotation, we will get
```
4   8   12   16 
3   7   11   15 
2   6   10   14 
1   5   9    13
```
How can we do to achieve that?  
We can divide this into two parts.  
First, we can do reflection over diagonal.
```
   Original                reflection
1   2   3   4            1   5   9   13
5   6   7   8    ----\   2   6   10  14
9   10  11  12   ----/   3   7   11  15
13  14  15  16           4   8   12  16
```
Then it's obvious. We just need to swap the `i` line with `n - 1 - i` line.
```
  reflection                 Result
1   5   9   13           4   8   12   16
2   6   10  14   ----\   3   7   11   15
3   7   11  15   ----/   2   6   10   14
4   8   12  16           1   5   9    13
```
### Code
```cpp
void transpose(int matrix[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1, j < 4; ++j)
        {
            swap(a[i][j], a[j][i]);
        }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; i < 4; ++j)
        {
            swap[matrix[i][j], matrix[4 - 1 - i][j]];
        }
    }
    }
}
```