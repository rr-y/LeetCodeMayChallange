/*
Problem Statement-> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/
Idea -> Binary Search
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, h = num;
        bool ans = false;
        while(l <= h){
            long long mid = l + (h-l)/2;
            if(mid*mid == num){
                ans = true;
                break;
            }
            
            else if(mid*mid > num)
                h = mid-1;
            else
                l = mid+1;
        }
            
        return ans;
    }
};
