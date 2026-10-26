class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
    string p = strs[0];
    for (auto& s : strs) {
    size_t i = 0;
    while (i < p.size() && i < s.size() && p[i] == s[i]) i++;
    p.resize(i);
    }
    return p;
    }
    };