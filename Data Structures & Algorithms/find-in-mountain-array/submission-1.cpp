class Solution {
    public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 0, r = n - 1;
    while (l < r) { int m = (l + r) / 2; if (mountainArr.get(m) < mountainArr.get(m + 1)) l = m + 1; else r = m; }
    int peak = l;
    l = 0; r = peak;
    while (l <= r) { int m = (l + r) / 2, v = mountainArr.get(m); if (v == target) return m; if (v < target) l = m + 1; else r = m - 1; }
    l = peak + 1; r = n - 1;
    while (l <= r) { int m = (l + r) / 2, v = mountainArr.get(m); if (v == target) return m; if (v > target) l = m + 1; else r = m - 1; }
    return -1;
    }
    };