class Solution {
public:

    int row;
    int col;

    bool findrest(vector<vector<char>>& board, int i,int j, int idx, string &word)
    {
        if(idx>=word.length())
        {
            return true;
        }
        if(i<0||i>=row||j<0||j>=col)
        {
            return false;
        }
        if(word[idx]!=board[i][j])
        {
            return false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        if(findrest(board,i+1,j,idx+1,word))
        {
            return true;
        }
        if(findrest(board,i-1,j,idx+1,word))
        {
            return true;
        }
        if(findrest(board,i,j+1,idx+1,word))
        {
            return true;
        }
        if(findrest(board,i,j-1,idx+1,word))
        {
            return true;
        }
        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();
        col=board[0].size();
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(board[i][j]==word[0]&&findrest(board,i,j,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};