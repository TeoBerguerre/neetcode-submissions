class CountSquares {
    map<pair<int,int>, int> cnt;
    public:
    CountSquares() {}
    void add(vector<int> point) { cnt[{point[0], point[1]}]++; }
    int count(vector<int> point) {
    int px = point[0], py = point[1], res = 0;
    for (auto& [p, c] : cnt) {
    int x = p.first, y = p.second;
    if (abs(x - px) != abs(y - py) || x == px) continue;
    auto a = cnt.find({x, py}), b = cnt.find({px, y});
    if (a != cnt.end() && b != cnt.end()) res += c * a->second * b->second;
    }
    return res;
    }
    };