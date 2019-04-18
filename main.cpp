#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void fillrand(int n,int m,vector<vector<int>> &a)
{
	srand(time(NULL));
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			{
				a[i][j]=rand()%2;
			}
	}
}

void outp(int n,int m,vector<vector<int>> &a)
{
	for (int i=0;i<n;i++)
	{
		cout << endl;
		for (int j=0;j<m;j++)
			{
				cout << a[i][j] << " ";
			}
	}
}
void logic(int n,int m,vector<vector<int>> &a)
{
	int f,c[n*m]={0},i,j;
	f=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (i==(n-1)&&j==(m-1))
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][j-1]+c[f];
				c[f]=a[i-1][0]+c[f];
				c[f]=a[i][0]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[0][j-1]+c[f];
				c[f]=a[0][j]+c[f];
				c[f]=a[0][0]+c[f];
			}
			else if (i==(n-1)&&j==0)
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][m-1]+c[f];
				c[f]=a[i-1][j+1]+c[f];
				c[f]=a[i][j+1]+c[f];
				c[f]=a[i][m-1]+c[f];
				c[f]=a[0][m-1]+c[f];
				c[f]=a[0][j]+c[f];
				c[f]=a[0][j+1]+c[f];
			}
			else if (i==0&&j==0)
			{
				c[f]=a[n-1][j]+c[f];
				c[f]=a[n-1][m-1]+c[f];
				c[f]=a[n-1][j-1]+c[f];
				c[f]=a[i][m-1]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i+1][m-1]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][j-1]+c[f];
			}
			else if (i==0&&j==(m-1))
			{
				c[f]=a[n-1][j]+c[f];
				c[f]=a[n-1][0]+c[f];
				c[f]=a[n-1][j-1]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i][0]+c[f];
				c[f]=a[i+1][0]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][j-1]+c[f];
			}
			else if (i==(n-1)&&(j!=(m-1)||j!=0))
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][j+1]+c[f];
				c[f]=a[i-1][j-1]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i][j+1]+c[f];
				c[f]=a[0][j+1]+c[f];
				c[f]=a[0][j]+c[f];
				c[f]=a[0][j-1]+c[f];
			}
			else if (i==0&&(j!=(m-1)||j!=0))
			{
				c[f]=a[n-1][j]+c[f];
				c[f]=a[n-1][j+1]+c[f];
				c[f]=a[n-1][j-1]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i][j+1]+c[f];
				c[f]=a[i+1][j-1]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][j+1]+c[f];
			}
			else if ((i!=(n-1)||i!=0)&&j==(m-1))
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][j-1]+c[f];
				c[f]=a[i-1][0]+c[f];
				c[f]=a[i][0]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i+1][j-1]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][0]+c[f];
			}
			else if ((i!=(n-1)||i!=0)&&j==0)
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][m-1]+c[f];
				c[f]=a[i-1][j+1]+c[f];
				c[f]=a[i][j+1]+c[f];
				c[f]=a[i][m-1]+c[f];
				c[f]=a[i+1][m-1]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][j+1]+c[f];
			}
			else
			{
				c[f]=a[i-1][j]+c[f];
				c[f]=a[i-1][j-1]+c[f];
				c[f]=a[i-1][j+1]+c[f];
				c[f]=a[i][j+1]+c[f];
				c[f]=a[i][j-1]+c[f];
				c[f]=a[i+1][j-1]+c[f];
				c[f]=a[i+1][j]+c[f];
				c[f]=a[i+1][j+1]+c[f];
			}
			f++;
		}
	}
	f=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (a[i][j]==0&&c[f]==3) a[i][j]=1;
			else if (a[i][j]==0&&c[f]!=3) a[i][j]=0;
			if (a[i][j]==1&&(c[f]==2||c[f]==3)) a[i][j]=1;
			else if (a[i][j]==1&&(c[f]!=2||c[f]!=3)) a[i][j]=0;
			f++;
		}
	}
	for (f=0;f<n*m;f++) c[f]=0;
}
int main()
{
	int n=10,m=10;
	vector<vector<int>> a(n,vector<int>(m,0));
	fillrand(n,m,a);
	int l=0;
		while(l<100)
		{
			l++;
//			cout << endl << "_________________________________" << endl;
			outp(n,m,a);
			logic(n,m,a);
			
		}
	return 0;
}
