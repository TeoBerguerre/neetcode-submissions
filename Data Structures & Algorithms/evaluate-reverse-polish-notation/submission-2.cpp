class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> myStack;
        static const std::unordered_map<std::string_view, int(*)(int,int)> ops = {
            {"+", [](int a, int b){ return a + b; }},
            {"-", [](int a, int b){ return a - b; }},
            {"*", [](int a, int b){ return a * b; }},
            {"/", [](int a, int b){ return a / b; }},
        };
        
        int result = 0;
        for (auto const& token: tokens) {
            if (auto searchOp = ops.find(token); searchOp != ops.end()) {
                int elementToComputeWith = std::stoi(myStack.top());
                myStack.pop();
                int baseElementToComputeWith = std::stoi(myStack.top());
                myStack.pop();
                int opResult = searchOp->second(baseElementToComputeWith, elementToComputeWith);
                myStack.push(std::to_string(opResult));
            } else {
                myStack.push(token);
            }
        }
        return std::stoi(myStack.top());
    }
};
