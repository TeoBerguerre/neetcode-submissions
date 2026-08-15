class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        std::unordered_map<string, vector<string>> _results;
        for (const auto& s: words) {
            std::string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            _results[sortedS].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : _results) {
            result.push_back(pair.second);
        }
        return result;
    }
};
