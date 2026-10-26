class Solution {
    public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;
    vector<vector<char>> r(n, vector<char>(n, 0));
    for (auto& p : prerequisites) r[p[0]][p[1]] = 1;
    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++) if (r[i][k])
    for (int j = 0; j < n; j++) if (r[k][j]) r[i][j] = 1;
    vector<bool> res;
    for (auto& q : queries) res.push_back(r[q[0]][q[1]]);
    return res;
    }
    };