#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_index;
        for (int i = 0; i < (int)nums.size(); i++) {
            int diff = target - nums[i];
            if (num_index.find(diff) != num_index.end()) {
                return { num_index[diff], i };
            }
            num_index.insert({ nums[i], i });
        }
        return { };
    }
};

struct TestCase {
    std::pair< std::vector<int>, int> input;
    std::vector<int> expected;
};

std::vector<TestCase> test_cases = {
    { { { 2, 7, 11, 15 }, 9 }, { 0, 1 }},
    { { { 3, 2, 4 }, 6 }, { 1, 2 }},
    { { { 3, 3 }, 6 }, { 0, 1 }}
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::vector<int> res = s.twoSum(test_cases[i].input.first, test_cases[i].input.second);
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