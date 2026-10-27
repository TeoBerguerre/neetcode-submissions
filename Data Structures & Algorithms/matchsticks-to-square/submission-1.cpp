class Solution {
    public:
    bool go(vector<int>& m, int i, long long side, vector<long long>& sides) {
    if (i == (int)m.size()) return sides[0] == side && sides[1] == side && sides[2] == side;
    for (int s = 0; s < 4; s++) {
    if (sides[s] + m[i] > side) continue;
    bool dup = false;
    for (int t = 0; t < s; t++) if (sides[t] == sides[s]) { dup = true; break; }
    if (dup) continue;
    sides[s] += m[i];
    if (go(m, i + 1, side, sides)) return true;
    sides[s] -= m[i];
    }
    return false;
    }
    bool makesquare(vector<int>& matchsticks) {
    long long sum = 0;
    for (int x : matchsticks) sum += x;
    if (sum % 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    vector<long long> sides(4, 0);
    return go(matchsticks, 0, sum / 4, sides);
    }
    };