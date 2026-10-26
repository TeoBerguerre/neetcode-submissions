class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (char c : tasks) cnt[c - 'A']++;
        int mx = *max_element(cnt, cnt + 26);
        int mxCount = count(cnt, cnt + 26, mx);
        return max((int)tasks.size(), (mx - 1) * (n + 1) + mxCount);
    }
};