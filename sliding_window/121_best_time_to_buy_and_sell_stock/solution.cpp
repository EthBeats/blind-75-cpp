#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int maxProfit = 0;
        int minPrice = prices[0];
        // dynamic programming reduced to two variables in a sliding window
        for (int &price : prices) {
            maxProfit = std::max(maxProfit, price - minPrice);
            minPrice = std::min(minPrice, price);
        }
        return maxProfit;
    }
};

struct TestCase
{
    std::vector<int> input;
    int expected;
};

static std::vector<TestCase> test_cases = {
    { { 10, 1, 5, 6, 7, 1 }, 6 },
    { { 10, 8, 7, 5, 2 }, 0 }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        int res = s.maxProfit(test_cases[i].input);
        std::cout << "Test " << i + 1 << ": ";
        if (res == test_cases[i].expected) {
            std::cout << "✅" << std::endl;
            passed++;
        } else {
            std::cout << "❌" << std::endl;
        }
    }
    std::cout << (passed == (int)test_cases.size() ? "all tests passed! 🔥" : "cooked 💀") << std::endl;
    return 0;
}