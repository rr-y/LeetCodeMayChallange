// Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

// Idea -> Sime map store and lookup later


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};
