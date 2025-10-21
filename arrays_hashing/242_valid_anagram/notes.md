# 242 - Valid Anagram

Ethan T Miller  
2025-10-21  

## Brief
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

*anagram*: a word or phrase formed by rearranging the letters of a different word or phrase.

## Explanation
In order to determine if `t` is an anagram of `s`, we can use a hash map to count the occurrences of each character in both strings. We then compare the two maps; if they are identical, `t` is an anagram of `s`.

*can either use two hash maps or vector to increment and decrement counts and check if all counts are zero at the end*

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)` (since the character set is limited)

Another approach is to sort both strings and compare them directly. If the sorted versions of both strings are equal, then `t` is an anagram of `s`.

**Time Complexity:** `O(nlogn)`  
**Space Complexity:** `O(1) or O(n)`