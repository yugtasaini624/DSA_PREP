/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

void getNodes(TreeNode *root,vector<vector<int>> &nodes){
    if(root==nullptr)return;

    queue<TreeNode*> q;
    vector<int> arr;
    q.push(root);

    while(!q.empty()){
        int size=q.size();

        for(int i=0;i<size;i++){
            TreeNode *temp=q.front();

            arr.push_back(temp->val);

            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }

            q.pop();
        }
        nodes.push_back(arr);
        arr.clear();
    }
}

vector<int> rightSideView(TreeNode* root){
    vector<int> ans;
    vector<vector<int>> nodes;
    if(root==NULL)return {};

    getNodes(root,nodes);

    for(auto &arr:nodes){
        ans.push_back(arr.back());
    }

    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(4);

    vector<int> ans=rightSideView(root);

    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}
