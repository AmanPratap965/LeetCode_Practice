class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        //checking for 8 directions of this row & col
        //checking up
        int r=row;
        int c=col;
        while(r>=0){
            if(board[r--][c]=='Q')return false;
        }
        r=row;c=col;
        //checking down
        while(r<n){
           if(board[r++][c]=='Q')return false;
        }
        r=row;c=col;
        //checking left
        while(c>=0){
            if(board[r][c--]=='Q')return false;
        }
        c=col;r=row;
        //checking right
        while(c<n){
            if(board[r][c++]=='Q')return false;
        }
        c=col;r=row;
        //checking up-left
        while(c>=0 && r>=0){
            if(board[r--][c--]=='Q')return false;
        }
            c=col;r=row;
        //checking up-right
        while(r>=0 && c<n){
            if(board[r--][c++]=='Q')return false;
        }
        c=col;r=row;
        //checking bottom-left
        while(r<n && c>=0){
            if(board[r++][c--]=='Q')return false;
        }
        c=col;r=row;
        //checking bottom-right
        while(r<n && c<n){
            if(board[r++][c++]=='Q')return false;
        }

        return true;
    }
    void solve(int col,vector<string>board,vector<vector<string>>&ans,int n){
       if(col==n){
        ans.push_back(board);
        return;
       }
       for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
       }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n);
       for(int i=0;i<n;i++)board[i]=s;
        solve(0,board,ans,n);
        return ans;
    }
};