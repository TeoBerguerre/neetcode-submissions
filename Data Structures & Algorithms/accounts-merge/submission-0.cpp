class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    unordered_map<string, int> owner;
    for (int i = 0; i < n; i++)
    for (size_t j = 1; j < accounts[i].size(); j++) {
    auto it = owner.find(accounts[i][j]);
    if (it == owner.end()) owner[accounts[i][j]] = i;
    else par[find(i)] = find(it->second);
    }
    map<int, vector<string>> groups;
    for (auto& [email, i] : owner) groups[find(i)].push_back(email);
    vector<vector<string>> res;
    for (auto& [root, emails] : groups) {
    sort(emails.begin(), emails.end());
    vector<string> row{accounts[root][0]};
    row.insert(row.end(), emails.begin(), emails.end());
    res.push_back(row);
    }
    return res;
    }
    };