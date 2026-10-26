class Solution {
    public:
    int openLock(vector<string>& deadends, string target) {
    unordered_set<string> seen(deadends.begin(), deadends.end());
    if (seen.count("0000")) return -1;
    queue<string> q; q.push("0000"); seen.insert("0000");
    int steps = 0;
    while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
    string s = q.front(); q.pop();
    if (s == target) return steps;
    for (int i = 0; i < 4; i++) {
    for (int d : {1, 9}) {
    string t = s;
    t[i] = char('0' + (t[i] - '0' + d) % 10);
    if (!seen.count(t)) { seen.insert(t); q.push(t); }
    }
    }
    }
    steps++;
    }
    return -1;
    }
    };