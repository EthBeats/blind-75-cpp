#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string> > ana;
        for (const std::string &s : strs) {
            std::vector<int> count(26, 0);
            for (const char c : s) {
                count[c - 'a']++;
            }
            std::string key = std::to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + std::to_string(count[i]);
            }
            ana[key].push_back(s);
        }
        std::vector< std::vector<std::string> > res;
        for (std::pair<const std::string, std::vector<std::string> > &p : ana) {
            res.push_back(p.second);
        }
        return res;
    }
};

struct TestCase
{
    std::vector<std::string> input;
    std::vector< std::vector<std::string> > expected;
};

static std::vector<TestCase> test_cases = {
    { { "act", "pots", "tops", "cat", "stop", "hat" }, { { "hat" }, { "act", "cat" }, { "stop", "pots", "tops" } } },
    { { "x" }, { { "x" } } },
    { { "" }, { { "" } } }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::vector< std::vector<std::string> > res = s.groupAnagrams(test_cases[i].input);
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