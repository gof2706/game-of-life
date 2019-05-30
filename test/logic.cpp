#include "catch.hpp"
#include "game.h"
int logic(int n, int m, std::vector< std::vector< int > >& a,int b)
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
	 i=3,j=3;
     a[i][j]=b;
	f=18;
            if (a[i][j] == 0 && c[f] == 3){
                a[i][j] = 1;
		return 0;}
            else if (a[i][j] == 0 && c[f] != 3){
                a[i][j] = 0;
		return 1;}
            if (a[i][j] == 1 && (c[f] == 2 || c[f] == 3)){
                a[i][j] = 1;
		return 2;}
            else if (a[i][j] == 1 && (c[f] != 2 || c[f] != 3)){
                a[i][j] = 0;
		return 3;}
}
TEST_CASE("test logic","[logic]")
{
	int n=5,m=5;
	vector<vector<int>> a(n, vector< int >(m, 0));
	a[2][2]=1;
	a[3][2]=1;
	a[4][2]=1;
	REQUIRE(logic(m,n,a,0)==0);
	a[2][3]=1;
	REQUIRE(logic(m,n,a,0)==1);
	a[2][3]=0;
	REQUIRE(logic(m,n,a,1)==2);
	a[2][2]=0;
	a[3][2]=0;
	a[4][2]=0;
	REQUIRE(logic(m,n,a,1)==3);
}
