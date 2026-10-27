class Solution {
    public:
    bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    vector<int> reach(n, 0);
    reach[0] = 1;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
    if (i - minJump >= 0) cnt += reach[i - minJump];
    if (i - maxJump - 1 >= 0) cnt -= reach[i - maxJump - 1];
    reach[i] = (s[i] == '0' && cnt > 0);
    }
    return reach[n - 1];
    }
    };