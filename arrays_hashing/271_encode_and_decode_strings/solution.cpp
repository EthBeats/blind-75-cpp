#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string encode(std::vector<std::string> &strs)
    {
        std::string result = "";
        for (std::string s : strs) {
            result += std::to_string(s.size()) + '#' + s;
        }
        return result;
    }

    std::vector<std::string> decode(std::string &s)
    {
        std::vector<std::string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int length = std::stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return result;
    }
};

struct TestCase
{
    std::vector<std::string> input;
    std::vector<std::string> expected;
};

static std::vector<TestCase> test_cases = {
    { { "we", "say", ":", "yes" }, { "we", "say", ":", "yes" } },
    { { "moose", "monk", "bailey", "bleu" }, { "moose", "monk", "bailey", "bleu" } },
    { { "This", "string", "is", "wack", "##,", "[]{}" }, { "This", "string", "is", "wack", "##,", "[]{}" } }
};

int main()
{
    Solution s;
    int passed = 0;
    for (size_t i = 0; i < test_cases.size(); i++) {
        std::string encoded = s.encode(test_cases[i].input);
        std::vector<std::string> decoded = s.decode(encoded);
        std::cout << "Test " << i + 1 << ": ";
        if (decoded == test_cases[i].expected) {
            std::cout << "✅" << std::endl;
            passed++;
        } else {
            std::cout << "❌" << std::endl;
        }
    }
    std::cout << (passed == (int)test_cases.size() ? "all tests passed! 🔥" : "cooked 💀") << std::endl;
    return 0;
}