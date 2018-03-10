#include<bits/stdc++.h>
using namespace std;

// x= horizonal y= going to bottom right z=going to bottom left

int grid[201][201];
int n=10;

void map_func(vector<int> l, int x, int y, int z)
{
	if(x)
	{
		for(int i=100-x+1;i<=100+x-1;i++)
			grid[x][i]=l[i+x-101];
	}
	else if(y)
	{
		int i=101-y, j=y;
		int k=0,p=-1;
		while(j<=n&&k<l.size())
		{
			grid[j][i]=l[k++];
			if(p==-1)
			{
				j++;
				p=1;
			}	
			else
			{
				i++;
				p=-1;
			}
		}
	}
	else
	{
		int i=99+y, j=y;
		int k=0,p=-1;
		while(j<=n&&k<l.size())
		{
			grid[j][i]=l[k++];
			if(p==-1)
			{
				j++;
				p=1;
			}	
			else
			{
				i--;
				p=-1;
			}
		}
	}

}

void print_grid()
{
	for (int i=1;i<=n;i++)
	{
		for(int k=0;k<n-i;k++)
		cout<<" ";
		for(int j=100-i+1;j<=100+i-1;j++)
		{
			if(grid[i][j]==1)
			cout<<"*";
			else
			cout<<"%";
		}
		for(int k=0;k<n-i;k++)
		cout<<" ";
		cout<<endl;
	}
	
/*	for(int i=0;i<11;i++)
		{
			for(int j=50;j<150;j++)
			{
				if(grid[i][j]==2)
				cout<<"$";
				else if(grid[i][j]==1)
					cout<<"*";
				else if(grid[i][j]==0)
					cout<<"#";
			}	

			cout<<endl;
		}*/	
}

void initialize()
{
	for(int i=0;i<201;i++)
		{
			for(int j=0;j<201;j++)
			grid[i][j]=2;
		}	
}

int main()
{
	vector<int> l;

	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);

	initialize();

	map_func(l,0,7,0);

	print_grid();

	return 0;
}
