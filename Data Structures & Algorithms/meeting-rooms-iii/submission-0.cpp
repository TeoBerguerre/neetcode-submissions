class Solution {
    public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    priority_queue<int, vector<int>, greater<int>> freeRooms;
    for (int i = 0; i < n; i++) freeRooms.push(i);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;
    vector<int> cnt(n, 0);
    for (auto& m : meetings) {
    long long s = m[0], e = m[1];
    while (!busy.empty() && busy.top().first <= s) { freeRooms.push(busy.top().second); busy.pop(); }
    if (!freeRooms.empty()) {
    int r = freeRooms.top(); freeRooms.pop();
    busy.push({e, r}); cnt[r]++;
    } else {
    auto [t, r] = busy.top(); busy.pop();
    busy.push({t + (e - s), r}); cnt[r]++;
    }
    }
    return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
    };