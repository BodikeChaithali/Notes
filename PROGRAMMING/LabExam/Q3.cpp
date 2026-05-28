#include <bits/stdc++.h>
using namespace std;

// Write your logic inside this function
void solveTestcase(int m, int n, vector<string> &board) {
    int vis[m][n];
    queue.pair()
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<string> board(m);
        for (int i = 0; i < m; i++) {
            cin >> board[i];
        }

        solveTestcase(m, n, board);

        // Print modified board
        for (auto &row : board)
            cout << row << "\n";
        cout << "\n";
    }
}