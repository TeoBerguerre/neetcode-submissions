class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> myStack;
        std::vector<int> results (temperatures.size(), 0);
        // empty
        // insert <30, index>
        // <38, index> > <30, index> ? pop 30 -> temp[<30, index>] =  (index38 - index30)
        // insert <38, index>
        // <30, index> > <38, index> ? no -> insert <30, index>
        // <36, index36> > <30, index30> ? yes -> pop <36, index36> -> temps[index30] = index36 - index30

        for (int i = 0; i < temperatures.size(); i++) {
            while (!myStack.empty() && temperatures[i] > myStack.top().first) {
                std::pair<int, int> elementToCompare = myStack.top();
                myStack.pop();
                results.at(elementToCompare.second) = (i - elementToCompare.second);
            }   
            myStack.push({temperatures[i], i});
        }
        return results;
    }
};
