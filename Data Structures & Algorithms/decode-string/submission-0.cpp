class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string cur;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '[') { st.push({cur, num}); cur.clear(); num = 0; }
            else if (c == ']') {
                auto [prev, k] = st.top(); st.pop();
                string rep;
                for (int i = 0; i < k; i++) rep += cur;
                cur = prev + rep;
            } else cur += c;
        }
        return cur;
    }
};