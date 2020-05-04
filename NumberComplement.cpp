//Problem ->  https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
// Idea -> Complement Checking

class Solution {
public:
    int findComplement(int num) {
        int compN = 0, i=0;
        while(num){
            int r = num%2;
            if(r == 0)
                compN += pow(2, i);
            num = num/2;
            i++;
        }
        return compN;
    }
};
