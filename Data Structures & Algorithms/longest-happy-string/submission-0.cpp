class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) pq.emplace(a, 'a');
        if (b) pq.emplace(b, 'b');
        if (c) pq.emplace(c, 'c');
        string res;
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            int n = res.size();
            if (n >= 2 && res[n - 1] == ch && res[n - 2] == ch) {
                if (pq.empty()) break;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                if (cnt2 > 1) pq.emplace(cnt2 - 1, ch2);
                pq.emplace(cnt, ch);
            } else {
                res += ch;
                if (cnt > 1) pq.emplace(cnt - 1, ch);
            }
        }
        return res;
    }
};