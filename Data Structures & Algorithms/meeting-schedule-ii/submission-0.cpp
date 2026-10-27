class Solution {
    public:
    int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> s, e;
    for (auto& iv : intervals) { s.push_back(iv.start); e.push_back(iv.end); }
    sort(s.begin(), s.end()); sort(e.begin(), e.end());
    int rooms = 0, best = 0;
    size_t j = 0;
    for (size_t i = 0; i < s.size(); i++) {
    while (j < e.size() && e[j] <= s[i]) { j++; rooms--; }
    rooms++;
    best = max(best, rooms);
    }
    return best;
    }
    };