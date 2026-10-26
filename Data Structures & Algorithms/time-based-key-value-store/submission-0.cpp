class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";
        auto& v = it->second;
        int lo = 0, hi = (int)v.size() - 1, ans = -1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (v[m].first <= timestamp) { ans = m; lo = m + 1; } else hi = m - 1;
        }
        return ans < 0 ? "" : v[ans].second;
    }
};