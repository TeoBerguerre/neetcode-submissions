class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for (std::size_t i = 0; i < s.size(); i++) {
            char& currentChar = s[i];
            if (isEntryBracket(currentChar)) {
                vec.push_back(currentChar);
            } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
                if (vec.empty() || !isMatchingCombination(vec.back(), currentChar)) {
                    return false;
                }
                    vec.pop_back();
                
            } else {
                return false;
            }
        }
        return vec.empty();
    }
private:
    bool isEntryBracket(char& c) {
        return c == '(' || c == '{' || c == '[';
    };
    bool isMatchingCombination(char &oldC, char& newC) {
        if (oldC == '(' && newC == ')') {
            return true;
        } else if (oldC == '{' && newC == '}') {
            return true;
        } else if (oldC == '[' && newC == ']') {
            return true;
        } else {
            return false;
        }
    }
};
