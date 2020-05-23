// Problem Statement -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

// Idea -> Dynamic Programming Approach


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        // dp[i][j] -> no of square matrices ending at that cell
        int maxCount = 0;
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++){
                int count = 0;
                if(matrix[i][j] == 1)
                    count += 1;
                // check 
                
                if(i-1 >= 0 && j-1 >= 0 && matrix[i][j]){
                    if(dp[i-1][j-1] && dp[i-1][j] && dp[i][j-1]){
                        count += min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                    }
                }
                
                dp[i][j] = count;
                maxCount += count;
                // cout<<count<< " ";
            }
            // cout<<endl;
        }
        return maxCount;
    }
};
