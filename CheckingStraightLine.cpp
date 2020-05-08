//Problem Statement->  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
// Idea -> Basic of Coordinate Geometry


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x = (coordinates[1][0]-coordinates[0][0]);
        int y = (coordinates[1][1]-coordinates[0][1]);
        
        
        for(int i=2;i<coordinates.size();i++){
            int x1 = (coordinates[i][0]-coordinates[i-1][0]);
            int y1 = (coordinates[i][1]-coordinates[i-1][1]);
            if(y1*x != x1*y)
                return false;
        }
        
        return true;
    }
};
