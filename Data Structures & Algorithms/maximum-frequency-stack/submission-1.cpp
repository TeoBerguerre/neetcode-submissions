class FreqStack {
    unordered_map<int, int> freq;
    vector<vector<int>> groups;
    public:
    FreqStack() {}
    void push(int val) {
    int f = ++freq[val];
    if ((int)groups.size() < f) groups.push_back({});
    groups[f - 1].push_back(val);
    }
    int pop() {
    int v = groups.back().back();
    groups.back().pop_back();
    if (groups.back().empty()) groups.pop_back();
    freq[v]--;
    return v;
    }
    };