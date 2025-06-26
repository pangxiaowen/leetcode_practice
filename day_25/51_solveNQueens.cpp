#include <string>
#include <vector>

using namespace std;

// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

std::vector<std::vector<std::string>> result;
std::vector<std::string> path;

bool is_vailed(int n, int col, int row, std::vector<std::string> &path)
{
    for (int i = 0; i < row; i++)
    {
        if (path[i][col] == 'Q')
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (path[i][j] == 'Q')
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (path[i][j] == 'Q')
            return false;
    }

    return true;
}

void backTracking(int n, int row, std::vector<std::string> &path)
{
    if (n == row)
    {
        result.push_back(path);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (is_vailed(n, col, row, path))
        {
            path[row][col] = 'Q';
            backTracking(n, row + 1, path);
            path[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{

    std::vector<std::string> path(n, std::string(n, '.'));
    backTracking(n, 0, path);
    return result;
}

int main()
{
    int n = 4;
    solveNQueens(4);
    return 0;
}
