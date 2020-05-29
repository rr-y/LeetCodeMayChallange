//Problem Link-> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/
// Idea -> Topological sort


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> >  graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        // define a queue
        queue<int> q;
        int visitC = 0;
        
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            visitC++;
            for(auto e : graph[top]){
                inDegree[e]--;
                if(inDegree[e] == 0)
                    q.push(e);
            }
        }
        
        return visitC == numCourses;
        
    }
};
