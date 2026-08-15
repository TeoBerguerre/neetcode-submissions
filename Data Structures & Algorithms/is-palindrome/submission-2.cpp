class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        bool isPalindrome = true;
        while (j > i) {
            if (!isalnum((unsigned char)s[i])) { 
                i++; continue; 
            }
            if (!isalnum((unsigned char)s[j])) { 
                j--; continue;
            }
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
