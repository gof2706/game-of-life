#include "game.h"
void filldroz(int n, int m, std::vector< std::vector< int > >& a)
{
    vector< int > t;
    fstream f;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    f.open("../src/txt/droz.txt", ios::in);

    int x;
    if (!f)
        cout << "holy shit" << endl;
    while (!f.eof()) {
        f >> x;
        t.push_back(x);
    }
    f.close();
    for (unsigned int i = 0, j = 1;j < t.size(); i += 2, j += 2) {
        a[t[i]][t[j]] = 1;
    }
}
