# 217 - Contains Duplicate

Ethan T Miller  
2025-10-17  

## Brief
Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Explanation
To determine if there are any duplicate values in the array, we can use a hash set to keep track of the elements we have seen so far. As we iterate through the array, we check if the current element is already in the set. If it is, we return `true` immediately. If we finish iterating through the array without finding any duplicates, we return `false`.

We can also compare the size of the set to the size of the array; if they differ, it indicates that there were duplicates.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

Another option is to sort the array and check for consecutive identical elements.

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(1) or O(n)`

The *brute force* approach would involve nested loops to compare each element with every other element, but this is less efficient.

**Time Complexity:** `O(n^2)`  
**Space Complexity:** `O(1)`