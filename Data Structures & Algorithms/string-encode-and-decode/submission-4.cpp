class Solution {
    public:
    string encode(vector<string>& strs) {
    string out;
    for (auto& s : strs) out += to_string(s.size()) + "#" + s;
    return out;
    }
    vector<string> decode(string s) {
    vector<string> res;
    size_t i = 0;
    while (i < s.size()) {
    size_t j = s.find('#', i);
    int len = stoi(s.substr(i, j - i));
    res.push_back(s.substr(j + 1, len));
    i = j + 1 + len;
    }
    return res;
    }
    };