#include <iostream>
#include <string>
#include <cctype>
#include <vector>

class Solution
{
public:
    // reverse string
    // bool isPalindrome(std::string s)
    // {
    //     std::string str;
    //     // check for alphanumeric & convert characters to lowercase
    //     for (char c : s) {
    //         if (isalnum(c)) {
    //             str += tolower(c);
    //         }
    //     }
    //     // reverse string with iterators & compare
    //     return str == std::string(str.rbegin(), str.rend());
    // }

    // two pointers
    bool isPalindrome(std::string s)
    {
        std::string str;
        // set up pointers
        int left = 0, right = s.length() - 1;
        while (left < right) {
            // skip invalid characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // advance pointers
            left++;
            right--;
        }
        return true;
    }
};

struct TestCase
{
    std::string input;
    bool expected;
};

static std::vector<TestCase> test_cases = {
    { "Was it a car or a cat I saw?", true },
    { "tab a cat", false }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        bool res = s.isPalindrome(test_cases[i].input);
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