// Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

// Idea -> Sorting




var majorityElement = function(nums) {
    nums.sort((a, b) => a-b);
    let len = nums.length;
    return nums[Math.floor(len/2)];
};
