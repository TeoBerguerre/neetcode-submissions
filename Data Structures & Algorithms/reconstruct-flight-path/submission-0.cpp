class Solution {
    public:
    unordered_map<string, multiset<string>> g;
    vector<string> route;
    void visit(const string& a) {
    auto& dests = g[a];
    while (!dests.empty()) {
    string b = *dests.begin();
    dests.erase(dests.begin());
    visit(b);
    }
    route.push_back(a);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (auto& t : tickets) g[t[0]].insert(t[1]);
    visit("JFK");
    reverse(route.begin(), route.end());
    return route;
    }
    };