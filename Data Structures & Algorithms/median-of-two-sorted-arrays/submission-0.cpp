class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        a.reserve(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(a));
        int n = a.size();
        if (n % 2) return a[n / 2];
        return (a[n / 2 - 1] + (double)a[n / 2]) / 2.0;
    }
};