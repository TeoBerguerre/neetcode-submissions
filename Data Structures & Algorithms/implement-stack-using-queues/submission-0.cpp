class MyStack {
    queue<int> q;
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 0; i + 1 < (int)q.size(); i++) { q.push(q.front()); q.pop(); }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};