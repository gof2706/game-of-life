#include "game.h"
using namespace std;
extern void fillrand(int n, int m, vector<vector<int>>& a);
extern void logic(int n, int m, vector<vector<int>>& a);
extern void outp(int n, int m, vector<vector<int>>& a);

int main()
{
    int n = 18, m = 18;
    vector<vector<int>> a(n, vector<int>(m, 0));
    fillrand(n, m, a);
    int l = 0;
    while (l < 100) {
        l++;
        system("CLS");
        outp(n, m, a);
        logic(n, m, a);
    }
    return 0;
}
