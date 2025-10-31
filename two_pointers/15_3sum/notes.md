# 15 - 3Sum

## Brief
Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

## Explanation
To solve the 3Sum problem, we can use a two-pointer technique after sorting the array. The idea is to fix one element and then use two pointers to find pairs that sum up to the negative of the fixed element.

**Time Complexity:** `O(n^2)`
**Space Complexity:** `O(1)` (excluding the space for the output)

The brute-force approach would involve three nested loops to check all possible triplets.

**Time Complexity:** `O(n^3)`
**Space Complexity:** `O(n)`