#include <bits/stdc++.h>
using namespace std;

int n;

void print(vector<vector<int>> board)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";

        }
        cout<<"\n";
    }
}

bool  isSafe(int row,int col,vector<bool> rows,vector<bool> left_diagonal,vector<bool>right_diagonal)
{
    if(rows[row] == true|| left_diagonal[row+col]==true || right_diagonal[col-row+n-1]==true)
    {
        return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board,int col,vector<bool> rows,vector<bool>left_diagonal,vector<bool>right_diagonal)
{
    if(col>=n)
    {
        return true;
    }

    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col,rows,left_diagonal,right_diagonal)==true)
        {
            rows[i]=true;
            left_diagonal[i+col]=true;
            right_diagonal[col-i+n-1]=true;
            board[i][col]=1;

            if(solve(board,col+1,rows,left_diagonal,right_diagonal))
            {
                return true;
            }

            rows[i]=false;
            left_diagonal[col+i]=false;
            right_diagonal[col-i+n-1]=false;
            board[i][col]=0;
        }
    }
    return false;
}


int main()
{
    cout<<"Enter the number of rows for sqaure matrix: ";
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<bool>rows(n,false);
    vector<bool>left_diagonal(2*n-1,false);
    vector<bool>right_diagonal(2*n-1,false);

    bool ans = solve(board,0,rows,left_diagonal,right_diagonal);

    if(ans==true)
        print(board);

    else cout<<"\nNo solution";

    return 0;

}
