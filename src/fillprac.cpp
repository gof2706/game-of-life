#include "game.h"
void fillprac(int n, int m, std::vector< std::vector< int > >& a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    vector< int > t;
    fstream f;

    f.open("../txt/prac.txt", ios::in);

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
