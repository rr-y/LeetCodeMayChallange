// Problem Statement -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/
//Idea -> Heap

class Solution {
public:
    
    string frequencySort(string s) {
        priority_queue<pair<int, char> > pq;
        map<char, int> m;
        for(auto e: s)
            m[e] += 1;
        
        // iterate over map
        for(auto e: m){
            pq.push({e.second, e.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            char c = top.second;
            int count = top.first;
            while(count--){
                ans += c;
            }
        }
        
        return ans;
    }
};
