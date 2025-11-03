# 11 - Container With Most Water

## Brief
Given n non-negative integers `height[0], height[1], ..., height[n-1]` where each represents a point at coordinate `(i, height[i])`. n vertical lines are drawn such that the two endpoints of line i is at `(i, height[i])` and `(i, 0)`. Find two lines, which together with x-axis forms a container, such that the container contains the most water.

## Explanation
To solve this problem, we can use the two-pointer technique. The idea is to start with two pointers, one at the beginning and one at the end of the array. We calculate the area formed by the lines at these two pointers and the x-axis. The area is determined by the shorter line, as the water cannot exceed the height of the shorter line.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

The brute force approach would involve checking all possible pairs of lines to find the maximum area.

**Time Complexity:** `O(n^2)`
**Space Complexity:** `O(1)`