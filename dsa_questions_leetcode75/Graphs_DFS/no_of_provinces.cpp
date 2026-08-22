/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.


Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>> &isConnected, unordered_set<int> &visited){
        visited.insert(city);

        for(int curr = 0;curr < isConnected[city].size();curr++){
            int connected = isConnected[city][curr];
            if(connected == 1 && visited.find(curr) == visited.end()){
                dfs(curr, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        int provinces = 0;

        for(int i = 0;i < isConnected.size();i++){
            if(visited.find(i) == visited.end()){
                dfs(i, isConnected, visited);
                provinces++;
            }
        } 
        return provinces;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int ans = obj.findCircleNum(isConnected);

    cout<<"Number of provinces: "<<ans<< endl;

    return 0;
}