class Solution {
    public:
    string longestDiverseString(int a, int b, int c) {
    string res;
    int cnt[3] = {a, b, c};
    while (true) {
    int order[3] = {0, 1, 2};
    sort(order, order + 3, [&](int x, int y) { return cnt[x] > cnt[y]; });
    bool placed = false;
    for (int k = 0; k < 3; k++) {
    int i = order[k];
    if (cnt[i] == 0) break;
    int n = res.size();
    if (n >= 2 && res[n - 1] == 'a' + i && res[n - 2] == 'a' + i) continue;
    res += char('a' + i); cnt[i]--; placed = true;
    break;
    }
    if (!placed) break;
    }
    return res;
    }
    };