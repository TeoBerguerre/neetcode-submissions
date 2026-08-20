class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n);
        std::vector<int> pref(n);
        std::vector<int> suff(n);
        pref[0] = 1;
        suff[n - 1] = 1;
        //lets take index = 1; -> value is 2
        // 1, 2 , 3 ,4

        for (int i = 1; i < n; i++) {
        //     std::cout << i << " -> ";
        //     std::cout << nums[i - 1] << " -> ";
        //     std::cout << pref[i - 1] << " -> ";
            pref[i] = nums[i - 1] * pref[i - 1];
            // std::cout << pref[i] << "\n";
        }
        //  std::cout << " ----- " << "\n";
        for (int i = n - 2; i >= 0; i--) {
            // std::cout << i << " -> ";
            // std::cout << nums[i + 1] << " -> ";
            // std::cout << pref[i + 1] << " -> ";
            suff[i] = nums[i + 1] * suff[i + 1];
            // std::cout << suff[i] << "\n";
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};
