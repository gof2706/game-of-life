#include "game.h"
void outp(int n, int m, std::vector< std::vector< int > >& a)
{
    for (int i = 0; i < n; i++) {
        std::cout << std::endl;
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
    }
}
