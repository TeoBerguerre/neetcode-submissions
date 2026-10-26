class Solution {
    public:
    bool isPalindrome(string s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
    if (!isalnum((unsigned char)s[l])) { l++; continue; }
    if (!isalnum((unsigned char)s[r])) { r--; continue; }
    if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
    l++; r--;
    }
    return true;
    }
    };