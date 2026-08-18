/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

Constraints:
    The number of nodes in each tree will be in the range [1, 200].
    Both of the given trees will have values in the range [0, 200].
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *root, vector<int> &arr){
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            arr.push_back(root->val);
            return;
        }

        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;

        dfs(root1, arr1);
        dfs(root2, arr2);

        if(arr1.size() != arr2.size()) return false;

        for(int i = 0;i < arr1.size();i++){
            if(arr1[i] != arr2[i]) return false;
        }

        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);

    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution obj;

    cout<<obj.leafSimilar(root, root1);

    return 0;
}