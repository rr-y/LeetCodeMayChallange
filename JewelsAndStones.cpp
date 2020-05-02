// Problem Link->  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

// Idea -> Lookup into a hash table


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> mp;
        int count=0;
        for(int i=0;i<J.length();i++)
            mp[J[i]] = 1;
        
        for(int i=0;i<S.length();i++){
            if(mp.find(S[i]) != mp.end()) count++;
        }
        
        return count;
    }
};
