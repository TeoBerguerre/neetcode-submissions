class Solution {
    public:
    string foreignDictionary(vector<string>& words) {
    bool present[26] = {false};
    for (auto& w : words) for (char c : w) present[c - 'a'] = true;
    vector<set<int>> adj(26);
    int indeg[26] = {0};
    for (size_t i = 1; i < words.size(); i++) {
    const string &a = words[i - 1], &b = words[i];
    size_t j = 0;
    while (j < a.size() && j < b.size() && a[j] == b[j]) j++;
    if (j == min(a.size(), b.size())) { if (a.size() > b.size()) return ""; continue; }
    int u = a[j] - 'a', v = b[j] - 'a';
    if (adj[u].insert(v).second) indeg[v]++;
    }
    queue<int> q;
    int total = 0;
    for (int c = 0; c < 26; c++) if (present[c]) { total++; if (indeg[c] == 0) q.push(c); }
    string res;
    while (!q.empty()) {
    int u = q.front(); q.pop();
    res += char('a' + u);
    for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    return (int)res.size() == total ? res : "";
    }
    };