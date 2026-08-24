class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1;
        // int high = *max_element(piles.begin(), piles.end());
        int high = piles[size - 1];
        int bestValue = high;
        while (low <= high) {
            int k = (low + high) / 2;
            if (canEatAllBananas(piles, size, k, h) == -1) {
                bestValue = k;
                high = k - 1;
            } else if (canEatAllBananas(piles, size, k, h) == 1){
                low = k + 1;
            }
        }
        return bestValue;
    };
    int canEatAllBananas(std::vector<int> &piles, int pileSize, int k, int h) {
        int sumHours = 0;
        for (int i = 0; i < pileSize; i++) {
            sumHours += (piles[i] + k - 1) / k;
            //not enough hours to eat all so we need to eat more per hour -> augment lower bound
            if (sumHours > h) {
                return 1;
            }
        }
        //seems like a correct solution ? but we could maybe improve so try another lower value -> reduce high bound
        if (sumHours <= h) {
            return -1;
        } 
        return -1;
    }
};
