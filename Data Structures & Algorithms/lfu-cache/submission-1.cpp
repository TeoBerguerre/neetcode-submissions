class LFUCache {
    int cap, minFreq = 0;
    unordered_map<int, tuple<int, int, list<int>::iterator>> data;
    unordered_map<int, list<int>> buckets;
    void touch(int key) {
    auto& [val, f, it] = data[key];
    buckets[f].erase(it);
    if (buckets[f].empty()) { buckets.erase(f); if (minFreq == f) minFreq++; }
    f++;
    buckets[f].push_front(key);
    it = buckets[f].begin();
    }
    public:
    LFUCache(int capacity) : cap(capacity) {}
    int get(int key) {
    if (!data.count(key)) return -1;
    touch(key);
    return get<0>(data[key]);
    }
    void put(int key, int value) {
    if (cap == 0) return;
    if (data.count(key)) { get<0>(data[key]) = value; touch(key); return; }
    if ((int)data.size() == cap) {
    int victim = buckets[minFreq].back();
    buckets[minFreq].pop_back();
    if (buckets[minFreq].empty()) buckets.erase(minFreq);
    data.erase(victim);
    }
    minFreq = 1;
    buckets[1].push_front(key);
    data[key] = {value, 1, buckets[1].begin()};
    }
    };