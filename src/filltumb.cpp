#include "game.h"
void filltumb(int n, int m, std::vector< std::vector< int > >& a)
{
    int g;
    vector< int > t;
    fstream f;

    f.open("../src/txt/tumb.txt", ios::in);

    int x;
    if (!f)
        cout << "holy shit" << endl;
    while (!f.eof()) {
        f >> x;
        t.push_back(x);
    }
    f.close();
    for (int i = 0, j = 1; i < t.size(), j < t.size(); i += 2, j += 2) {
        a[t[i]][t[j]] = 1;
    }
}
