#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxSeq = 0;
        for (const int &n : hashSet) {
            if (!hashSet.count(n - 1)) {
                int len = 1;
                while (hashSet.count(n + len)) len++;
                maxSeq = std::max(maxSeq, len);
            }
        }
        return maxSeq;
    }
};

struct TestCase
{
    std::vector<int> input;
    int expected;
};

static std::vector<TestCase> test_cases = {
    { { 2, 20, 4, 10, 3, 4, 5 }, 4 },
    { { 0, 3, 2, 5, 4, 6, 1, 1 }, 7 }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        int res = s.longestConsecutive(test_cases[i].input);
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