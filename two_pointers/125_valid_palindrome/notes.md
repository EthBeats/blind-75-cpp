# 125 - Valid Palindrome

## Brief
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

## Explanation
To solve this problem, we can use the two-pointer technique. We will initialize two pointers:
- One pointer (`left`) starting at the beginning of the string.
- Another pointer (`right`) starting at the end of the string.
We will then iterate through the string, moving the pointers towards each other while skipping non-alphanumeric characters. At each step, we will compare the characters at the two pointers. If they are not equal (ignoring case), we can conclude that the string is not a palindrome. If the pointers cross each other without finding any mismatches, the string is a palindrome.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

Another option is to reverse the cleaned string and compare it to the original cleaned string.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`