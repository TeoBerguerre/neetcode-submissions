class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res{""};
        for (char d : digits) {
            vector<string> nxt;
            for (auto& p : res) for (char c : m[d - '0']) nxt.push_back(p + c);
            res.swap(nxt);
        }
        return res;
    }
};