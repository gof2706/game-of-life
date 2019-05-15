#include "game.h"
void logic(int n, int m, std::vector<std::vector<int>>& a)
{
    int f, c[n * m] = {0}, i, j;
    f = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == (n - 1) && j == (m - 1)) {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][j - 1] + c[f];
                c[f] = a[i - 1][0] + c[f];
                c[f] = a[i][0] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[0][j - 1] + c[f];
                c[f] = a[0][j] + c[f];
                c[f] = a[0][0] + c[f];
            } else if (i == (n - 1) && j == 0) {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][m - 1] + c[f];
                c[f] = a[i - 1][j + 1] + c[f];
                c[f] = a[i][j + 1] + c[f];
                c[f] = a[i][m - 1] + c[f];
                c[f] = a[0][m - 1] + c[f];
                c[f] = a[0][j] + c[f];
                c[f] = a[0][j + 1] + c[f];
            } else if (i == 0 && j == 0) {
                c[f] = a[n - 1][j] + c[f];
                c[f] = a[n - 1][m - 1] + c[f];
                c[f] = a[n - 1][j - 1] + c[f];
                c[f] = a[i][m - 1] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i + 1][m - 1] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][j - 1] + c[f];
            } else if (i == 0 && j == (m - 1)) {
                c[f] = a[n - 1][j] + c[f];
                c[f] = a[n - 1][0] + c[f];
                c[f] = a[n - 1][j - 1] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i][0] + c[f];
                c[f] = a[i + 1][0] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][j - 1] + c[f];
            } else if (i == (n - 1) && (j != (m - 1) || j != 0)) {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][j + 1] + c[f];
                c[f] = a[i - 1][j - 1] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i][j + 1] + c[f];
                c[f] = a[0][j + 1] + c[f];
                c[f] = a[0][j] + c[f];
                c[f] = a[0][j - 1] + c[f];
            } else if (i == 0 && (j != (m - 1) || j != 0)) {
                c[f] = a[n - 1][j] + c[f];
                c[f] = a[n - 1][j + 1] + c[f];
                c[f] = a[n - 1][j - 1] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i][j + 1] + c[f];
                c[f] = a[i + 1][j - 1] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][j + 1] + c[f];
            } else if ((i != (n - 1) || i != 0) && j == (m - 1)) {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][j - 1] + c[f];
                c[f] = a[i - 1][0] + c[f];
                c[f] = a[i][0] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i + 1][j - 1] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][0] + c[f];
            } else if ((i != (n - 1) || i != 0) && j == 0) {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][m - 1] + c[f];
                c[f] = a[i - 1][j + 1] + c[f];
                c[f] = a[i][j + 1] + c[f];
                c[f] = a[i][m - 1] + c[f];
                c[f] = a[i + 1][m - 1] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][j + 1] + c[f];
            } else {
                c[f] = a[i - 1][j] + c[f];
                c[f] = a[i - 1][j - 1] + c[f];
                c[f] = a[i - 1][j + 1] + c[f];
                c[f] = a[i][j + 1] + c[f];
                c[f] = a[i][j - 1] + c[f];
                c[f] = a[i + 1][j - 1] + c[f];
                c[f] = a[i + 1][j] + c[f];
                c[f] = a[i + 1][j + 1] + c[f];
            }
            f++;
        }
    }
    f = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 0 && c[f] == 3)
                a[i][j] = 1;
            else if (a[i][j] == 0 && c[f] != 3)
                a[i][j] = 0;
            if (a[i][j] == 1 && (c[f] == 2 || c[f] == 3))
                a[i][j] = 1;
            else if (a[i][j] == 1 && (c[f] != 2 || c[f] != 3))
                a[i][j] = 0;
            f++;
        }
    }
    for (f = 0; f < n * m; f++)
        c[f] = 0;
}
