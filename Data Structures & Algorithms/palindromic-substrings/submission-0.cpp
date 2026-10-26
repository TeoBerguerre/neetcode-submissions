class Solution {
    public:
    int countSubstrings(string s) {
    int n = s.size(), cnt = 0;
    for (int c = 0; c < n; c++) {
    for (int odd = 0; odd < 2; odd++) {
    int l = c, r = c + odd;
    while (l >= 0 && r < n && s[l] == s[r]) { cnt++; l--; r++; }
    }
    }
    return cnt;
    }
    };