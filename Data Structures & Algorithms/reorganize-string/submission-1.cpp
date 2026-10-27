class Solution {
    public:
    string reorganizeString(string s) {
    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;
    priority_queue<pair<int,char>> pq;
    for (int i = 0; i < 26; i++) if (cnt[i]) pq.push({cnt[i], char('a' + i)});
    string res;
    pair<int,char> prev = {0, 0};
    while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    res += cur.second;
    cur.first--;
    if (prev.first > 0) pq.push(prev);
    prev = cur;
    }
    return res.size() == s.size() ? res : "";
    }
    };