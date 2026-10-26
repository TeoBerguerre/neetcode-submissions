class LFUCache {
    int cap, minFreq = 0;
    unordered_map<int, tuple<int, int, list<int>::iterator>> kv; // key -> (value, freq, pos)
    unordered_map<int, list<int>> buckets;                       // freq -> keys, MRU at front
    void touch(int key) {
        auto& [val, f, pos] = kv[key];
        buckets[f].erase(pos);
        if (buckets[f].empty()) { buckets.erase(f); if (minFreq == f) minFreq++; }
        f++;
        buckets[f].push_front(key);
        pos = buckets[f].begin();
    }
public:
    LFUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        if (!kv.count(key)) return -1;
        touch(key);
        return std::get<0>(kv[key]);
    }
    void put(int key, int value) {
        if (cap == 0) return;
        if (kv.count(key)) { std::get<0>(kv[key]) = value; touch(key); return; }
        if ((int)kv.size() == cap) {
            auto& b = buckets[minFreq];
            int evict = b.back();
            b.pop_back();
            if (b.empty()) buckets.erase(minFreq);
            kv.erase(evict);
        }
        minFreq = 1;
        buckets[1].push_front(key);
        kv[key] = {value, 1, buckets[1].begin()};
    }
};