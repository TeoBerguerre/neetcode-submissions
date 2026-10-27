class Solution {
    public:
    vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    const vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res = {""};
    for (char d : digits) {
    vector<string> next;
    for (auto& p : res) for (char c : m[d - '0']) next.push_back(p + c);
    res = next;
    }
    return res;
    }
    };