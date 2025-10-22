# 1 - Two Sum

Ethan T Miller  
2025-10-22  

## Brief
Given an array of integers `nums` and an integer `target`, return indices of the two numbers that add up to `target`. Assume exactly one solution, no same element twice.   

## Explanation

Use a hash map to store difference `target - j` to decrease complexity. Check for the difference in the map as you iterate through the array. If found, return the indices. Otherwise, store the current number and its index in the map.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

Sorting the array allows you to use a two pointer method to decrease complexity. 

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(n)`

The *brute force* method requires nested looping to check each combination of numbers to add up to the target.

**Time Complexity:** `O(n^2)`  
**Space Complexity:** `O(1)`