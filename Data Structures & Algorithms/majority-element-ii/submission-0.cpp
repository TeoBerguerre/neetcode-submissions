class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x]++;
        vector<int> res;
        for (auto& [k, v] : cnt) if (v > (int)nums.size() / 3) res.push_back(k);
        return res;
    }
};