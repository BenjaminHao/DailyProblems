# Question 1.7
## Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

## Thinking
An easy question. Iterate the matrix, if we find an element is 0, we get the row number and column number.  
We can have 2 arrays for rows and columns. When the element `a[i][j] = 0`, we set `row[i]` and `col[j]` to `true`.  
Then iterate the matrix agin, when `row[i]` or `col[j]` is `true`, we set the element to be 0.