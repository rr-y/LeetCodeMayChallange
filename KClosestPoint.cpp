//Problem -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/
// Idea -> Heap

int dist(vector<int> &a){
    return (a[0]*a[0] + a[1]*a[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;
        
        priority_queue<pair<int, pair<int,int> > > pq;
        vector<vector<int> > ans;
        for(int i=0;i<points.size();i++){
            int d = dist(points[i]);
            if(pq.size() < K){
                pq.push({d, {points[i][0], points[i][1]}});
                
            }
            else{
                if(pq.top().first > d){
                    pq.pop();
                    pq.push({d, {points[i][0], points[i][1]}});
                }
            }
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        
        return ans;
    }
};
