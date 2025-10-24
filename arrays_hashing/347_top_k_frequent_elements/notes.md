# 347 - Top K Frequent Elements

Ethan T Miller  
2025-10-24  

## Brief
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

## Explanation
We can solve this problem using a hash map to count the frequency of each element and use bucket sort to group elements by their frequencies. That way, we can efficiently retrieve the top `k` frequent elements.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

Sort the elements based on their frequencies and return the top `k` elements. Can reduce to `O(nlogk)` using a min-heap. (priority queue)

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(n)`