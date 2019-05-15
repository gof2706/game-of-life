#include "game.h"
void fillrand(int n, int m, std::vector< std::vector< int > >& a)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 2;
        }
    }
}
