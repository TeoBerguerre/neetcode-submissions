class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total = 0;
        int high = 0;
        for (int p : piles) {
            total += p;
            high = max(high, p);
        }
        int low = max(1LL, (total + h - 1) / h);

        while (low < high) {
            int k = low + (high - low) / 2;
            long long hours = 0;
            for (int p : piles) {
                hours += (p - 1) / k + 1;
                if (hours > h) break;
            }
            if (hours <= h) high = k;
            else            low = k + 1;
        }
        return low;
    }
};