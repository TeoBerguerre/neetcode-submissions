class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int x : nums) cnt[x]++;
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto& [v, c] : cnt) bucket[c].push_back(v);
    vector<int> res;
    for (int c = nums.size(); c > 0 && (int)res.size() < k; c--)
    for (int v : bucket[c]) if ((int)res.size() < k) res.push_back(v);
    return res;
    }
    };