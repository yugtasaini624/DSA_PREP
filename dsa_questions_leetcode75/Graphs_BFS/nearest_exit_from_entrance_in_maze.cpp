/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists. 

Example 1:

Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

Example 2:

Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

Example 3:

Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.

 

Constraints:

    maze.length == m
    maze[i].length == n
    1 <= m, n <= 100
    maze[i][j] is either '.' or '+'.
    entrance.length == 2
    0 <= entrancerow < m
    0 <= entrancecol < n
    entrance will always be an empty cell.

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    using pp=pair<int,int>;
    int nearestExit(vector<vector<char> >& nums,vector<int>& e){

        int m=nums.size();
        int n=nums[0].size();

        vector<pp>dir={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int> >v(m,vector<int>(n,INT_MAX));
        
        int x=e[0];
        int y=e[1];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]=='+') v[i][j]=-1;
            }
        }


        queue< pair<pp,int> >q;
        q.push({{x,y},0});
        v[x][y]=0;

        while(q.size()){

            auto f=q.front();
            q.pop();

            int x=f.first.first;
            int y=f.first.second;
            int d=f.second;

            for(auto ele:dir){

                int nx=x+ele.first;
                int ny=y+ele.second;

                if(nx>=0 && ny>=0 && nx<m && ny<n && v[nx][ny]!=-1){
                    if(v[nx][ny]==INT_MAX){
                        q.push({{nx,ny},d+1});
                        v[nx][ny]=d+1;
                    }
                    else{
                        if(v[nx][ny]>d+1) v[nx][ny]=d+1;
                    }
                }
            }
        }


        int mini=INT_MAX;
        v[x][y]=INT_MAX;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]!=-1 && (i==0 || i==m-1 || j==0 || j==n-1)){
                    mini=min(mini,v[i][j]);
                }
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;

    }
};

int main() {

    Solution obj;

    vector<vector<char>> maze = {
        {'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}
    };

    vector<int> entrance = {1,2};

    cout<<"Nearest Exit Distance: "<<obj.nearestExit(maze, entrance)<<endl;

    return 0;
}