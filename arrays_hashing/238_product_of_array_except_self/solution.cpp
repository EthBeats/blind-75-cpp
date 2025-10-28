#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};

struct TestCase
{
    std::vector<int> input;
    std::vector<int> expected;
};

static std::vector<TestCase> test_cases = {
    { { 1, 2, 4, 6 }, { 48, 24, 12, 8 } },
    { { -1, 0, 1, 2, 3 }, { 0, -6, 0, 0, 0 } }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::vector<int> res = s.productExceptSelf(test_cases[i].input);
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