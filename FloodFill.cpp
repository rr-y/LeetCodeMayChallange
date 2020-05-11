//Problem->  https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
// Idea-> Recursion




void floodFillAlgorithm(vector<vector<int> > &image, int sr, int sc, int newColor, int oldColor, vector<vector<int> > &visited){
    visited[sr][sc] = 1;
    image[sr][sc] = newColor;
    if(sr+1 < image.size() && sc < image[0].size() && sc >= 0 && sr >= 0 && image[sr+1][sc] == oldColor && !visited[sr+1][sc])
        floodFillAlgorithm(image, sr+1, sc, newColor, oldColor, visited);
    
    if(sr-1 < image.size() && sc < image[0].size() && sc >= 0 && sr >= 0 && image[sr-1][sc] == oldColor && !visited[sr-1][sc])
        floodFillAlgorithm(image, sr-1, sc, newColor, oldColor, visited);
    
    if(sr < image.size() && sc+1 < image[0].size() && sc >= 0 && sr >= 0 && image[sr][sc+1] == oldColor && !visited[sr][sc+1])
        floodFillAlgorithm(image, sr, sc+1, newColor, oldColor, visited);
    
    if(sr < image.size() && sc-1 < image[0].size() && sc >= 0 && sr >= 0 && image[sr][sc-1] == oldColor && !visited[sr][sc-1])
        floodFillAlgorithm(image, sr, sc-1, newColor, oldColor, visited);
}
    



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int> > visited(image.size(), vector<int>(image[0].size(), 0));
        floodFillAlgorithm(image, sr, sc, newColor, image[sr][sc], visited);
        return image;
    }
};
