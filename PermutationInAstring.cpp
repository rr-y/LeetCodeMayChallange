//Problem Link -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
//Idea -> Hash Map 



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
            return false;
        vector<int> arr(26, 0);
        for(auto e : s1)
            arr[(int)e-97] += 1;
        
        vector<int> zero(26, 0);
        vector<int> temp;
        for(int i=0;i<=s2.length()-s1.length();i++){
            temp  = arr;
            for(int j=0;j<s1.length();j++){
                --temp[(int)s2[i+j]-97];
                
            }
            
            if(temp == zero)
                return true;
        }
        
        return false;
    }
};
