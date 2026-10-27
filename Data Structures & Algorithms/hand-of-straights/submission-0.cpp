class Solution {
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize) return false;
    map<int, int> cnt;
    for (int x : hand) cnt[x]++;
    for (auto& [v, c] : cnt) {
    if (c == 0) continue;
    int need = c;
    for (int k = 0; k < groupSize; k++) {
    auto it = cnt.find(v + k);
    if (it == cnt.end() || it->second < need) return false;
    it->second -= need;
    }
    }
    return true;
    }
    };