class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> m;
    m.reserve(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(m));
    int n = m.size();
    if (n % 2) return m[n / 2];
    return (m[n / 2 - 1] + (double)m[n / 2]) / 2.0;
    }
    };