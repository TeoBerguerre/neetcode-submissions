class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) if (cnt[i]) pq.emplace(cnt[i], 'a' + i);
        string res;
        pair<int, char> held{0, 0};
        while (!pq.empty()) {
            auto [c, ch] = pq.top(); pq.pop();
            res += ch;
            if (held.first > 0) pq.push(held);
            held = {c - 1, ch};
        }
        return held.first > 0 ? "" : res;
    }
};