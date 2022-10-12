vector<vector<string>> ans;
class Solution
{
public:
    bool isSafe(vector<vector<bool>> &grid, int ro, int col, int n)
    {

        // col
        for (int i = ro - 1; i >= 0; i--)
        {
            if (grid[i][col] == 1)
                return 0;
        }
        // left diagonal
        for (int i = ro - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 1)
                return 0;
        }
        // right diagonal
        for (int i = ro - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (grid[i][j] == 1)
                return 0;
        }

        return 1;
    }
    void solve(vector<vector<bool>> &grid, vector<string> &ds, string s, int ro, int n)
    {
        if (ro == n)
        {
            for (int i = 0; i < ro; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                        s.push_back('Q');
                    else
                        s.push_back('.');
                }
                ds.push_back(s);
                s.clear();
            }
            ans.push_back(ds);
            ds.clear();
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isSafe(grid, ro, j, n))
            {
                grid[ro][j] = 1;
                solve(grid, ds, s, ro + 1, n);
                grid[ro][j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<bool>> grid(n, vector<bool>(n, 0));
        ans.resize(0, vector<string>(n, ""));
        vector<string> ds;
        string s;
        solve(grid, ds, s, 0, n);
        return ans;
    }
};