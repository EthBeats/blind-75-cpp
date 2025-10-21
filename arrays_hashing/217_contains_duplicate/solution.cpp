#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> S;
        for (int n : nums) {
            std::pair<std::unordered_set<int>::iterator, bool> res = S.insert(n);
            if (!res.second) {
                return true;
            }
        }
        return false;
    }
};

struct TestCase {
    std::vector<int> input;
    bool expected;
};

std::vector<TestCase> test_cases = {
    {{1, 2, 3, 1}, true},
    {{1, 2, 3, 4}, false},
    {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},
    {{}, false},
    {{0}, false},
    {{100000, -100000, 100000}, true},
    {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false},
    {{2, 2}, true},
    {{2147483647, -2147483648, 0, 2147483647}, true},
    {{2147483647, -2147483648, 0}, false}
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        bool res = s.containsDuplicate(test_cases[i].input);
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