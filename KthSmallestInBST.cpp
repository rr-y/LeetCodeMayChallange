// Problem -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
// Idea -> Traversal Technique


void findingKthSmallest(TreeNode* root, int& k, int &ans, bool &isThere){
    // base case
    if(root == NULL)
        return;
    
    // recursive case
    findingKthSmallest(root->left, k, ans, isThere);
    k--;
    if(k == 0){
        ans = root->val;
        isThere = true;
        return;
    }
    
    if(!isThere)
        findingKthSmallest(root->right, k, ans, isThere);
    
}


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        bool isThere = false;
        findingKthSmallest(root, k, ans, isThere);
        return ans;
    }
};
