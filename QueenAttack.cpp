/*
https://www.interviewbit.com/old/problems/queen-attack/
On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

Notes:

Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity is worst case O(N*M).

The following is O(n*m*(n+m)) case but works
*/
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int r=A.size();
    int c=A[0].size();
    vector<vector<int>> arr(r,vector<int> (c,0));
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //check left
            int count=0;
            for(int k=j-1;k>=0;k--)
            {
                if(A[i][k]=='1')
                {
                    count++;
                    break;
                }
            }
            
            //right
            for(int k=j+1;k<c;k++)
            {
                if(A[i][k]=='1')
                {
                    count++;
                    break;
                }
            }
            
            //top
            for(int k=i-1;k>=0;k--)
            {
                if(A[k][j]=='1')
                {
                    count++;
                    break;
                }
            }
            //bottom
            for(int k=i+1;k<r;k++)
            {
                if(A[k][j]=='1')
                {
                    count++;
                    break;
                }
            }
            //top left
            for(int k=i-1,l=j-1; k>=0 && l>=0; k--,l--)
            {
                if(A[k][l]=='1')
                {
                    count++;
                    break;
                }
            }
            //top right
            for(int k=i-1,l=j+1; k>=0 && l<c;k--,l++)
            {
                if(A[k][l]=='1')
                {
                    count++;
                    break;
                }
            }
            //bottom left
            for(int k=i+1,l=j-1;k<r&&l>=0;k++,l--)
            {
                if(A[k][l]=='1')
                {
                    count++;
                    break;
                }
            }
            //bottom right
            for(int k=i+1,l=j+1;k<r && l<c;k++,l++)
            {
                if(A[k][l]=='1')
                {
                    count++;
                    break;
                }
            }
            arr[i][j]=count;
        }
    }
    return arr;
}
