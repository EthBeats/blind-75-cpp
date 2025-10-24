#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> count;
        std::vector< std::vector<int> > freq(nums.size() + 1);
        for (int n : nums) {
            count[n] = count[n] + 1;
        }
        for (const auto &entry : count) {
            freq[entry.second].push_back(entry.first);
        }
        std::vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

struct TestCase
{
    std::pair< std::vector<int>, int> input;
    std::vector<int> expected;
};

static std::vector<TestCase> test_cases = {
    { { { 1, 1, 1, 2, 2, 3 }, 2 }, { 1, 2 } },
    { { { 1 }, 1 }, { 1 } },
    { { { 1, 2, 1, 2, 1, 2, 3, 1, 3, 2 }, 2 }, { 1, 2 } }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::vector<int> res = s.topKFrequent(test_cases[i].input.first, test_cases[i].input.second);
        std::sort(res.begin(), res.end());
        std::sort(test_cases[i].expected.begin(), test_cases[i].expected.end());
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