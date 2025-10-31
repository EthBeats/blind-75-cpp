#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector< std::vector<int> > threeSum(std::vector<int> &nums)
    {
        std::vector< std::vector<int> > result;
        // sort nums vector
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            // sorted, so cannot be larger than 0
            if (nums[i] > 0) break;
            // skip same first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // set up two pointers
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    result.push_back({ nums[i], nums[left], nums[right] });
                    left++; right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
            }
        }
        return result;
    }
};

struct TestCase
{
    std::vector<int> input;
    std::vector< std::vector<int> > expected;
};

static std::vector<TestCase> test_cases = {
    { { -1, 0, 1, 2, -1, -4 }, { { -1, -1, 2 }, { -1, 0, 1 } } },
    { { 0, 1, 1 }, {  } },
    { { 0, 0, 0 }, { { 0, 0, 0 } } }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::vector< std::vector<int> > res = s.threeSum(test_cases[i].input);
        for (auto &v : res) {
            std::sort(v.begin(), v.end());
        }
        for (auto &v : test_cases[i].expected) {
            std::sort(v.begin(), v.end());
        }
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