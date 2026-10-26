class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string p = strs[0];
        for (auto& s : strs) {
            int i = 0;
            while (i < (int)p.size() && i < (int)s.size() && p[i] == s[i]) i++;
            p.resize(i);
        }
        return p;
    }
};
