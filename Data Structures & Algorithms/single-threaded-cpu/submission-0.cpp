class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // (proc, index)
        vector<int> res;
        long long t = 0;
        int i = 0;
        while ((int)res.size() < n) {
            if (pq.empty() && t < tasks[idx[i]][0]) t = tasks[idx[i]][0];
            while (i < n && tasks[idx[i]][0] <= t) { pq.emplace(tasks[idx[i]][1], idx[i]); i++; }
            auto [p, id] = pq.top(); pq.pop();
            t += p;
            res.push_back(id);
        }
        return res;
    }
};