class Solution {
    public:
    int leastInterval(vector<char>& tasks, int n) {
    int cnt[26] = {0};
    for (char c : tasks) cnt[c - 'A']++;
    int mx = *max_element(cnt, cnt + 26), num = 0;
    for (int c : cnt) if (c == mx) num++;
    return max((int)tasks.size(), (mx - 1) * (n + 1) + num);
    }
    };