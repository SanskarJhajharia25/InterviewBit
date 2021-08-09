/*
https://leetcode.com/problems/check-if-move-is-legal/submissions/

You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) on a game board. On the board, free cells are represented by '.', white cells are represented by 'W', and black cells are represented by 'B'.

Each move in this game consists of choosing a free cell and changing it to the color you are playing as (either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint of a good line (horizontal, vertical, or diagonal).

A good line is a line of three or more cells (including the endpoints) where the endpoints of the line are one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). You can find examples for good lines in the figure below:
*/

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) 
    {
        char opp = color == 'B' ? 'W' : 'B'; //Stores the opposite colour that what we have
        //Defining the valid move pairs
        int a[8] = {0,0,1,-1,1,-1,-1,1};
        int b[8] = {1,-1,0,0,1,-1,1,-1};
        
        for(int k = 0; k < 8; ++k) 
        {//going one by one as per the direction
            int x = rMove + a[k], y = cMove + b[k];
            bool seenOpp = false, flag = false;
            for(; x >= 0 && y >= 0 && x < 8 && y < 8; x += a[k], y += b[k]) 
            {
                if(board[x][y] == '.') //Case when not occupied lines 
                  break;
                else if(board[x][y] != opp) 
                { //Case when the end of line is reached
                    flag = true;
                    break;
                }
                else if(!seenOpp) //Colour is opposite basically 
                  seenOpp = true;
            }
            if(seenOpp && flag) return true;
        }
        return false;
    }
};
