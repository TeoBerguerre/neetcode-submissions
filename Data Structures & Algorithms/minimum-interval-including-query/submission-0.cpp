class Solution {
    public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    sort(intervals.begin(), intervals.end());
    vector<int> qi(queries.size());
    for (size_t i = 0; i < qi.size(); i++) qi[i] = i;
    sort(qi.begin(), qi.end(), [&](int a, int b) { return queries[a] < queries[b]; });
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> res(queries.size(), -1);
    size_t i = 0;
    for (int q : qi) {
    int x = queries[q];
    while (i < intervals.size() && intervals[i][0] <= x) { pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]}); i++; }
    while (!pq.empty() && pq.top().second < x) pq.pop();
    if (!pq.empty()) res[q] = pq.top().first;
    }
    return res;
    }
    };