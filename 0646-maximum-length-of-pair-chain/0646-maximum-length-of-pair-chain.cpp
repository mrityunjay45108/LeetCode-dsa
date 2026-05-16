class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int longestChain =0 ;
        int currentEnd = INT_MIN;

        for (const auto& pair : pairs) {
            if (pair[0] > currentEnd) {
                longestChain++;
                currentEnd = pair[1];
            }
        }

        return longestChain;
    }
};