class Solution {
    public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> res;
    long long t = 0;
    int i = 0;
    while ((int)res.size() < n) {
    if (pq.empty() && t < tasks[idx[i]][0]) t = tasks[idx[i]][0];
    while (i < n && tasks[idx[i]][0] <= t) { pq.push({tasks[idx[i]][1], idx[i]}); i++; }
    auto [d, j] = pq.top(); pq.pop();
    t += d;
    res.push_back(j);
    }
    return res;
    }
    };