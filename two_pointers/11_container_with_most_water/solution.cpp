#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxArea(std::vector<int> &heights)
    {
        int maxArea = 0;
        // set up two pointers
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            // calculate area between left and right
            int area = (right - left) * std::min(heights[left], heights[right]);
            // update maxArea
            maxArea = std::max(maxArea, area);
            // update pointers
            if (heights[left] <= heights[right]) left++;
            else right--;
        }
        return maxArea;
    }
};

struct TestCase
{
    std::vector<int> input;
    int expected;
};

static std::vector<TestCase> test_cases = {
    { { 1, 7, 2, 5, 4, 7, 3, 6 }, 36 },
    { { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49 },
    { { 2, 2, 2 }, 4 }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        int res = s.maxArea(test_cases[i].input);
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