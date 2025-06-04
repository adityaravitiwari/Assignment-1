#include  <bits/stdc++.h>
using namespace std;

void helper(int col, int n, vector<int> &board, vector<bool> &rows, vector<bool> &diag1, vector<bool> &diag2,vector<vector<string>> &res) {
    if (col > n) {
        vector<string> config;
        for (int i = 0; i < n; ++i) {
            string row(n, '.');
            row[board[i] - 1] = 'Q';
            config.push_back(row);
        }
        res.push_back(config);
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!rows[i] && !diag1[i + col] && !diag2[i - col + n]) {
            rows[i] = diag1[i + col] = diag2[i - col + n] = true;
            board.push_back(i);

            helper(col + 1, n, board, rows, diag1, diag2, res);

            board.pop_back();
            rows[i] = diag1[i + col] = diag2[i - col + n] = false;
        }
    }
}

vector<vector<string>> nQueen(int n) {
    vector<vector<string>> res;
    vector<int> board;
    vector<bool> rows(n + 1, false);
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);
    helper(1, n, board, rows, diag1, diag2, res);
    return res;
}