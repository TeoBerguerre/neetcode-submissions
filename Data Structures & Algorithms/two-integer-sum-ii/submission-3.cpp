class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (r > l) {
            int tryResult = numbers[l] + numbers[r];
            if (tryResult == target) {
                return {++l, ++r};
            } else {
                if (tryResult > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return {0, 0};
    }
};
