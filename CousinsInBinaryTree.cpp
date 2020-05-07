//Problem Statement -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

// Idea -> Binary Tree Traversal and Passing the object

struct ansNode{
    int h, parentVal;
    bool isTrue;
    ansNode() : h(0), parentVal(0), isTrue(false) {}
};

void Cousins(TreeNode* root, int x, int y, ansNode** p1, ansNode** p2, int cHeight, int pVal){
    if(root == NULL) return;
    
    else if(root->val == x){
        (*p1)->h = cHeight;
        (*p1)->parentVal = pVal;
        (*p1)->isTrue = true;
    }
    
     else if(root->val == y){
        (*p2)->h = cHeight;
        (*p2)->parentVal = pVal;
        (*p2)->isTrue = true;
    }
    
    if(!((*p1)->isTrue && (*p2)->isTrue)){
        Cousins(root->left, x, y, p1, p2, cHeight+1, root->val);
        Cousins(root->right, x, y, p1, p2, cHeight+1, root->val);
    }
    return;
 
}


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        ansNode *p1 = new ansNode();
        ansNode *p2 = new ansNode();
        
        Cousins(root, x, y, &p1, &p2, 0, 0);
        
        if(p1->h == p2->h && p1->parentVal != p2->parentVal)
            return true;
        return false;
        
    }
};
