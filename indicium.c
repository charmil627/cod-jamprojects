#include <bits/stdc++.h>

using namespace std;

int rect[60][60], n, k, t;
bool row_safe[60][60], col_safe[60][60], nerf;
void calculate(int row, int col, int m) {
    if (row == n && col == n + 1 && m == k && !nerf) {
        nerf = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << rect[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (row > n) {
        return;
    } else if (col > n) {
        calculate(row + 1, 1, m);
    }
    for (int i = 1; i <= n && !nerf; ++i) {
        if (!row_safe[row][i] && !col_safe[col][i]) {
            row_safe[row][i] = col_safe[col][i] = true;
            if (row == col) {
                m += i;
            }
            rect[row][col] = i;

            calculate(row, col + 1, m);

            row_safe[row][i] = col_safe[col][i] = false;
            if (row == col) {
                m -= i;
            }
            rect[row][col] = 0;
        }
    }
}

int main() {
    int T;
    scanf(" %d", &T);
    for (t = 1; t <= T; ++t) {
        scanf(" %d %d", &n, &k);
        calculate(1, 1, 0);
        if (!nerf) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        nerf= false;
    }
    return 0;
}
