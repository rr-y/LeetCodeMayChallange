//Problem Link -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
//Idea -> Stack

class Solution {
public:
    string removeKdigits(string nums, int k) {
        string ans = "";
        stack<char> st;
        
        if(k >= nums.length())
            return "0";
        
        st.push(nums[0]);
        for(int i = 1;i<nums.length(); i++){
            while(!st.empty() && st.top() > nums[i] && k > 0){
                st.pop();
                k--;
            }
            
            st.push(nums[i]);
        }
        
        
        while(!st.empty()){
    
            while(k > 0 ){
                st.pop();
                k--;
            }
            ans = st.top() + ans;
            st.pop();
        }
        
        int i=0;
        while(ans[i] == '0')
            i++;
        
        if(i == ans.length())
            return "0";
        
        ans = ans.substr(i);
        return ans;
    }
};
