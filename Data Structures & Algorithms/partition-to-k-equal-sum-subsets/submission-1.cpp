class Solution {
    public:
    bool go(vector<int>& a, int i, int target, vector<int>& b) {
    if (i == (int)a.size()) return true;
    for (int s = 0; s < (int)b.size(); s++) {
    if (b[s] + a[i] > target) continue;
    bool dup = false;
    for (int t = 0; t < s; t++) if (b[t] == b[s]) { dup = true; break; }
    if (dup) continue;
    b[s] += a[i];
    if (go(a, i + 1, target, b)) return true;
    b[s] -= a[i];
    }
    return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int x : nums) sum += x;
    if (sum % k) return false;
    sort(nums.rbegin(), nums.rend());
    vector<int> b(k, 0);
    return go(nums, 0, sum / k, b);
    }
    };