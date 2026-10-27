class Solution {
    public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int,int>> proj(n);
    for (int i = 0; i < n; i++) proj[i] = {capital[i], profits[i]};
    sort(proj.begin(), proj.end());
    priority_queue<int> pq;
    int i = 0;
    while (k--) {
    while (i < n && proj[i].first <= w) pq.push(proj[i++].second);
    if (pq.empty()) break;
    w += pq.top(); pq.pop();
    }
    return w;
    }
    };