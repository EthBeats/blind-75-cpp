# 121 - Best Time to Buy and Sell Stock

## Brief
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

## Explanation
To solve the problem of finding the best time to buy and sell stock to maximize profit, we can use a single pass approach with two pointers or variables. The idea is to keep track of the minimum price seen so far and calculate the potential profit at each step by subtracting the current price from this minimum price. We update the maximum profit whenever we find a higher potential profit.

*simplified dynamic programming approach*

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

The brute force approach involves checking every possible pair of buy and sell days to calculate the profit. This can be done using two nested loops: the outer loop iterates through each day as a potential buy day, and the inner loop iterates through the subsequent days as potential sell days. For each pair, we calculate the profit and update the maximum profit if the current profit is higher.

**Time Complexity:** `O(n^2)`
**Space Complexity:** `O(1)`