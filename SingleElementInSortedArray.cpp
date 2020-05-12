//Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/
//Idea -> Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        
        // base cases
        if(nums.size() == 1 || nums[0] != nums[1])
            return nums[0];
        else if(nums[n-2] != nums[n-1])
            return nums[n-1];
        
        while(low<high){
            int mid =  low + (high-low)/2;
            
            // left or right;
            if((mid+1) <n && nums[mid] == nums[mid+1] && !(mid%2))
                low = mid+1;
            
            else if((mid-1) >= 0 && nums[mid] == nums[mid-1] && !((mid-1)%2))
                low = mid+1;
            
            else if((mid+1) <n && nums[mid] == nums[mid+1] && (mid%2))
                high = mid-1;
            
            else if((mid-1) >= 0 && nums[mid] == nums[mid-1] && ((mid-1)%2))
                high = mid-1;
            
            else if((mid+1) < n && (mid-1) >= 0 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
        }
        
        return nums[low];
        
    }
};
