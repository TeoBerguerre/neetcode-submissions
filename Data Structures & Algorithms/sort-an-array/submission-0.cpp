class Solution {
    void mergeSort(vector<int>& a, vector<int>& tmp, int l, int r) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        mergeSort(a, tmp, l, m);
        mergeSort(a, tmp, m, r);
        int i = l, j = m, k = l;
        while (i < m || j < r) {
            if (j >= r || (i < m && a[i] <= a[j])) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
        for (int t = l; t < r; t++) a[t] = tmp[t];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        mergeSort(nums, tmp, 0, nums.size());
        return nums;
    }
};