// Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
// Idea -> Hash Map


class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length() == 0)
            return -1;
        int ansIdx = 0, i=1;
        vector<int> table(26, 0);
        table[s[ansIdx]-97] = 1;
        while(i < s.length()){
            table[s[i]-97]++;
            while(ansIdx <= i && table[s[ansIdx]-97] > 1){
                ansIdx++;
            }
            i++;
        }
        
        return (ansIdx == s.length()) ? -1: ansIdx;
    }
};
