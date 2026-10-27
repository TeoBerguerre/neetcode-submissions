class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
    vector<long long> st;
    for (auto& t : tokens) {
    if (t.size() == 1 && string("+-*/").find(t[0]) != string::npos) {
    long long b = st.back(); st.pop_back();
    long long a = st.back(); st.pop_back();
    if (t == "+") st.push_back(a + b);
    else if (t == "-") st.push_back(a - b);
    else if (t == "*") st.push_back(a * b);
    else st.push_back(a / b);
    } else st.push_back(stoll(t));
    }
    return st.back();
    }
    };