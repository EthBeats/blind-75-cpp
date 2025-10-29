# 128 - Longest Consecutive Sequence

Ethan T Miller  
2025-10-29  

## Brief
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

## Explanation
You can solve this problem using a hash set to achieve an optimal time complexity of O(n). The idea is to store all the numbers in a set for O(1) access and then iterate through each number, checking if it's the start of a sequence (i.e., `num - 1` is not in the set). If it is the start, you can then count how long the consecutive sequence is by checking for `num + 1`, `num + 2`, etc. Finally, keep track of the maximum length found.

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(n)` or `O(1)` depending on the implementation.

Can also use sorting to solve this problem, but it results in a worse time complexity of O(n log n) due to the sort operation. After sorting, you can iterate through the array to find the longest consecutive sequence by comparing each number with the previous one.

The brute force approach involves looping through each number and possibly every number in a hash set resulting in a worse time complexity.

**Time Complexity:** `O(n^2)`  
**Space Complexity:** `O(n)`