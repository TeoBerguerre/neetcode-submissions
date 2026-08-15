class MinStack {
    vector<int> _stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        _stack.push_back(val);
    }
    
    void pop() {
        _stack.pop_back();
    }
    
    int top() {
        return _stack[_stack.size() - 1];
    }
    
    int getMin() {
        auto[min, max] = std::ranges::minmax(_stack);
        return min;
    }
};
