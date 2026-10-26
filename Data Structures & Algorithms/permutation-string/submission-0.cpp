class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        array<int, 26> a{}, b{};
        for (char c : s1) a[c - 'a']++;
        int n = s1.size();
        for (int i = 0; i < (int)s2.size(); i++) {
            b[s2[i] - 'a']++;
            if (i >= n) b[s2[i - n] - 'a']--;
            if (a == b) return true;
        }
        return false;
    }
};