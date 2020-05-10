/*
Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
Idea -> Graph Algorithm
*/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int ans = -1;
        
        vector<int> inDegree(N+1, 0);
        vector<int> outDegree(N+1, 0);
        for(int i=0;i<trust.size();i++){
            inDegree[trust[i][1]] += 1;
            outDegree[trust[i][0]] += 1;
        }
        
        for(int i=1;i<=N;i++){
            if(inDegree[i] == N-1 && outDegree[i] == 0)
                ans = i;
        }
        
        return ans;
    }
};
