class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> groups;
    int maxf = 0;
public:
    FreqStack() {}
    void push(int val) {
        int f = ++freq[val];
        maxf = max(maxf, f);
        groups[f].push_back(val);
    }
    int pop() {
        int v = groups[maxf].back();
        groups[maxf].pop_back();
        freq[v]--;
        if (groups[maxf].empty()) maxf--;
        return v;
    }
};