class LRUCache {
    int cap;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
    public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
    auto it = pos.find(key);
    if (it == pos.end()) return -1;
    lru.splice(lru.begin(), lru, it->second);
    return it->second->second;
    }
    void put(int key, int value) {
    auto it = pos.find(key);
    if (it != pos.end()) { it->second->second = value; lru.splice(lru.begin(), lru, it->second); return; }
    if ((int)lru.size() == cap) { pos.erase(lru.back().first); lru.pop_back(); }
    lru.push_front({key, value});
    pos[key] = lru.begin();
    }
    };