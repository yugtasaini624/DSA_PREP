/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:

    The number of nodes in the tree is in the range [0, 1000].
    -109 <= Node.val <= 109
    -1000 <= targetSum <= 1000
*/

#include<iostream>
#include<unordered_map>
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
    long long count = 0;
    long long currSum = 0;
    unordered_map<long long, long long> mp;

    void findSum(TreeNode *root, long long targetSum){
        if(!root) return;

        currSum += root->val;

        count += mp[currSum - targetSum];

        mp[currSum]++;

        findSum(root->left, targetSum);
        findSum(root->right, targetSum);

        mp[currSum]--;
        currSum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;

        findSum(root, targetSum);
        return count;
    }
};

int main() {

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    Solution obj;

    int targetSum = 8;

    cout<<"Number of paths: "<<obj.pathSum(root, targetSum)<<endl;

    return 0;
}