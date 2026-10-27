class Solution {
    public:
    string simplifyPath(string path) {
    vector<string> parts;
    stringstream ss(path);
    string tok;
    while (getline(ss, tok, '/')) {
    if (tok.empty() || tok == ".") continue;
    if (tok == "..") { if (!parts.empty()) parts.pop_back(); }
    else parts.push_back(tok);
    }
    string res;
    for (auto& p : parts) res += "/" + p;
    return res.empty() ? "/" : res;
    }
    };