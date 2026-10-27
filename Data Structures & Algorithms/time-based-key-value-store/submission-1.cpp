class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
    public:
    TimeMap() {}
    void set(string key, string value, int timestamp) { m[key].push_back({timestamp, value}); }
    string get(string key, int timestamp) {
    auto it = m.find(key);
    if (it == m.end()) return "";
    auto& v = it->second;
    int l = 0, r = (int)v.size() - 1;
    string res;
    while (l <= r) {
    int mid = (l + r) / 2;
    if (v[mid].first <= timestamp) { res = v[mid].second; l = mid + 1; } else r = mid - 1;
    }
    return res;
    }
    };