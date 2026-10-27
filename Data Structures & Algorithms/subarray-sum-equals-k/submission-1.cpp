class Solution {
    public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> seen{{0, 1}};
    int sum = 0, res = 0;
    for (int x : nums) {
    sum += x;
    auto it = seen.find(sum - k);
    if (it != seen.end()) res += it->second;
    seen[sum]++;
    }
    return res;
    }
    };