class Solution {
    public:
    string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    vector<int> d(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
    int p = (num1[i] - '0') * (num2[j] - '0') + d[i + j + 1];
    d[i + j + 1] = p % 10;
    d[i + j] += p / 10;
    }
    string res;
    for (int x : d) if (!(res.empty() && x == 0)) res += char('0' + x);
    return res.empty() ? "0" : res;
    }
    };