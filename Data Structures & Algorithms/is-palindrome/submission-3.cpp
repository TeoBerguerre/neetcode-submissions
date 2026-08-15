class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        bool isPalindrome = true;
        while (j > i) {
            if (!isalnum(s[i])) { 
                i++; continue; 
            }
            if (!isalnum(s[j])) { 
                j--; continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
