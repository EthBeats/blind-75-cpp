# 238 - Product of Array Except Self

Ethan T Miller  
2025-10-26  

## Brief
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`. The solution must run in `O(n)` time and without using division.

## Explanation
To solve the problem of finding the product of all elements in an array except for the element at each index, we can use a two-pass approach without division.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)` (excluding the output array)

The brute force approach would involve nested loops, resulting in `O(n^2)` time complexity, which is inefficient for large arrays.

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(n)`