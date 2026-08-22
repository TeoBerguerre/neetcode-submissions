class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int maxArea = 0;
        const int heightWidth = 1;
        std::stack<std::pair<int, int>> myStack;
        const int size = heights.size();
        for (int i = 0; i < size; i++) {
            int startOfThisHeight = i;
            while(!myStack.empty() && myStack.top().second > heights[i]) {
                // {0, 2}
                std::pair<int, int> currentPair = myStack.top();
                startOfThisHeight = currentPair.first; // the new pair is {0, 1} because 1 is also in 2
                // std::cout << "current Pair index : " << currentPair.first << " -> ";
                // std::cout << "current Pair height : " << currentPair.second << " -> ";
                const int calculatedHeight = heightWidth * (i - currentPair.first) * currentPair.second;
                // std::cout << "height calculated : " << calculatedHeight << "\n";
                // compare max 0 to (1 * indexWhere we need to pop - where we started to have this height (1 - 0))
                maxArea = std::max(maxArea, calculatedHeight);
                myStack.pop();
            }
            myStack.push({startOfThisHeight, heights[i]});
        }

        // we still have [{0,1}, {4,2}, {5, 3}] so we need to check if we have an area wort
        while (!myStack.empty()) {
            std::pair<int, int> currentPair = myStack.top();
            // std::cout << "2 - current Pair index : " << currentPair.first << " -> ";
            // std::cout << "current Pair height : " << currentPair.second << "\n";
            maxArea = std::max(maxArea, heightWidth * (size - currentPair.first) * currentPair.second);
            myStack.pop();
        }
        return maxArea;
    }
};
