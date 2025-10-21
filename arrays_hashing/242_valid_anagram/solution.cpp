#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::vector<int> count(26, 0);
        for (int i = 0; i < (int)s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int x : count) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};

struct TestCase
{
    std::string s;
    std::string t;
    bool expected;
};

int main()
{
    Solution s;
    std::vector<TestCase> test_cases = {
        {"racecar", "carrace", true},
        {"jar", "jam", false}
    };
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        bool res = s.isAnagram(test_cases[i].s, test_cases[i].t);
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