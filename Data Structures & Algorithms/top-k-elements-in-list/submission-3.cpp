class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> _listNumbers;

        for (int i = 0; i < nums.size(); ++i) {
            if (auto search = _listNumbers.find(nums[i]); search != _listNumbers.end()) {
                _listNumbers[nums[i]] = search->second + 1;
            } else {
                _listNumbers[nums[i]] = 1;
            }
        }

        std::vector<std::vector<int>> _frequenceOfNumbers;
        _frequenceOfNumbers.resize(nums.size() + 1, std::vector<int>());
          
        for (auto const& number: _listNumbers) {
            _frequenceOfNumbers[number.second].push_back(number.first);
        }

        std::vector<int> results;
        results.reserve(k);
        int numberOfElementsLeftToTake = k;
        for (int i = _frequenceOfNumbers.size() - 1; i >= 0; --i) {
            if (numberOfElementsLeftToTake == 0) {
                break;
            }
            int numberOfOccurring = _frequenceOfNumbers[i].size();
            if (numberOfOccurring > 0) {
                int numberOfElementsWeNeedToTakeFromThisBucket = numberOfOccurring > numberOfElementsLeftToTake ? numberOfElementsLeftToTake : numberOfOccurring;
                for (int j = 0; j < numberOfElementsWeNeedToTakeFromThisBucket; ++j) {
                    results.push_back(_frequenceOfNumbers[i][j]);
                }
                numberOfElementsLeftToTake -= numberOfElementsWeNeedToTakeFromThisBucket;
            } else {
                continue;
            }
        }

        return results;
    }
};