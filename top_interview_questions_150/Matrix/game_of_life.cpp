/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
Given the current state of the board, update the board to reflect its next state.
Note that you do not need to return anything.

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 25
    board[i][j] is 0 or 1.

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
        int liveNeighbours = 0;
        if(i>0) {
            //check the upper neighbour
            if(curr[i-1][j] == 1 || curr[i-1][j] == 3) liveNeighbours++;
        }
        if(i<m-1) {
            //check the lower neighbour
            if(curr[i+1][j] == 1 || curr[i+1][j] == 3) liveNeighbours++;
        }
        if(j>0) {
            //check the left neighbour
            if(curr[i][j-1] == 1 || curr[i][j-1] == 3) liveNeighbours++;
        }
        if(j<n-1) {
            //check the right neighbour
            if(curr[i][j+1] == 1 || curr[i][j+1] == 3) liveNeighbours++;
        }

        if(i>0 && j>0) {
            if(curr[i-1][j-1] == 1 || curr[i-1][j-1] == 3) liveNeighbours++;
        }
        if(i>0 && j<n-1) {
            if(curr[i-1][j+1] == 1 || curr[i-1][j+1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j>0) {
            if(curr[i+1][j-1] == 1 || curr[i+1][j-1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j<n-1) {
            if(curr[i+1][j+1] == 1 || curr[i+1][j+1] == 3) liveNeighbours++;
        }
        return liveNeighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int ln = getLiveNeighbours(board, i, j, m, n);
                if(board[i][j] == 0) {
                    //currently dead
                    //can become alive if has exactly three live neighbours
                    if(ln == 3) {
                        board[i][j] = 2; //newly alive
                    }
                }
                else if(board[i][j] == 1) {
                    //<2 -> die
                    //==2 || ==3 live
                    //>3 ->die
                    if(ln < 2 || ln > 3) {
                        board[i][j] = 3; //newly dead
                    }
                }
            }
        }
        //final modifications 2->1, 3->0
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1}
    };

    Solution obj;

    obj.gameOfLife(board);

    for(auto row : board) {
        for(auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}