/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.*/



int Solution::isValidSudoku(const vector<string> &A) {
     for(int i=0;i<9;i++){
            set<char>r;
            for(int j=0;j<9;j++)
                if(A[i][j]!='.')
                    if(r.count(A[i][j])==0)
                        r.insert(A[i][j]);
                    else return 0;
        }
        for(int i=0;i<9;i++){
            set<char>r;
            for(int j=0;j<9;j++)
                if(A[j][i]!='.')
                    if(r.count(A[j][i])==0)
                        r.insert(A[j][i]);
                    else return 0;
        }
        set<char>s[3][3];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                int r=i/3,c=j/3;
                if(A[i][j]!='.'){
                    if(s[r][c].count(A[i][j])==0)
                        s[r][c].insert(A[i][j]);
                    else return 0;
                }
            }
        return 1;
}
