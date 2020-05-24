// Problem Statement -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/
// Idea -> Building Tree

TreeNode* buildTree(vector<int>& preorder, vector<int> &inorder, int st, int ed){
    if(st > ed)
        return NULL;
    
    int val = preorder[0];
    preorder.erase(preorder.begin());
    TreeNode* root = new TreeNode(val);
    int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();
    root->left = buildTree(preorder, inorder, st, idx-1);
    root->right = buildTree(preorder, inorder, idx+1, ed);
    return root;
}



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        auto root = buildTree(preorder, inorder, 0, inorder.size()-1);
        return root;
    }
};
