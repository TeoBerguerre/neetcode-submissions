class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        stack.reserve(tokens.size());

        for (const string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                
                int right = stack.back();
                stack.pop_back();

                int left = stack.back();
                stack.pop_back();

                if (token == "+") {
                    stack.push_back(left + right);
                } else if (token == "-") {
                    stack.push_back(left - right);
                } else if (token == "*") {
                    stack.push_back(left * right);
                } else {
                    // C++ integer division truncates toward zero.
                    stack.push_back(left / right);
                }
            } else {
                stack.push_back(stoi(token));
            }
        }

        return stack.back();
    }
};
