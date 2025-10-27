# 271 - Encode and Decode Strings

Ethan T Miller  
2025-10-25  

## Brief
Design an algorithm to encode a list of strings to a single string. The encoded string can then be decoded back to the original list of strings.

## Explanation
To encode the list of strings, we can use a delimiter-based approach. We will choose a delimiter that is unlikely to appear in the strings themselves. A common choice is to use a special character sequence, such as `#`, after the length of the string, and then the string itself. This way, during decoding, we can easily identify where each string starts and ends.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`