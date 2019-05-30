#include "game.h"
void fillpuls(int n, int m, std::vector< std::vector< int > >& a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    vector< int > t;
    fstream f;

    f.open("../src/txt/puls.txt", ios::in);

    int x;
    while (!f.eof()) {
        f >> x;
        t.push_back(x);
        if (!f.eof()) {
        }
    }
    f.close();
    for (int i = 0, j = 1; i < t.size(), j < t.size(); i += 2, j += 2) {
        a[t[i]][t[j]] = 1;
    }
}
