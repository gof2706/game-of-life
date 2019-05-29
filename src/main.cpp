#include "game.h"
using namespace std;
extern void fillrand(int n, int m, vector< vector< int > >& a);
extern void logic(int n, int m, vector< vector< int > >& a);
extern void outp(int n, int m, vector< vector< int > >& a);
extern void fillbill(int n, int m, vector< vector< int > >& a);
extern void fillpuls(int n, int m, vector< vector< int > >& a);
extern void filldroz(int n, int m, vector< vector< int > >& a);
extern void fillpalk(int n, int m, vector< vector< int > >& a);
extern void fillprac(int n, int m, vector< vector< int > >& a);
extern void fillskre(int n, int m, vector< vector< int > >& a);
extern void filltumb(int n, int m, vector< vector< int > >& a);

int main()
{
    int n = 30, m = 30;
    vector< vector< int > > a(n, vector< int >(m, 0));
    //    fillrand(n, m, a);
    //	fillbill(n,m,a);
    //	filldroz(n,m,a);
    //	fillpalk(n,m,a);
    //	fillprac(n,m,a);
    //	fillskre(n,m,a);
    filltumb(n, m, a);
    //    fillpuls(n, m, a);
    int l = 0;
    while (l < 100) {
        l++;
        cout << endl;
        outp(n, m, a);
        logic(n, m, a);
    }
    return 0;
}
