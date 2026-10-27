class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> g;
    for (auto& s : strs) { string k = s; sort(k.begin(), k.end()); g[k].push_back(s); }
    vector<vector<string>> res;
    for (auto& [k, v] : g) res.push_back(v);
    return res;
    }
    };