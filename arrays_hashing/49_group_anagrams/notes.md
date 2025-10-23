# 49 - Group Anagrams

Ethan T Miller  
2025-10-23  

## Brief
Given an array of strings, group the anagrams together. You can return the answer in any order.

## Explanation
A hash map can store the count of each character in the string as a key, and the value would be a list of strings that match that character count.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

Sorting each string and using the sorted string as a key in a hash map is another effective approach.

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(n)`