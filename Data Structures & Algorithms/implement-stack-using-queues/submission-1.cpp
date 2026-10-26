class MyStack {
    queue<int> q;
    public:
    MyStack() {}
    void push(int x) {
    q.push(x);
    for (size_t i = 1; i < q.size(); i++) { q.push(q.front()); q.pop(); }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
    };