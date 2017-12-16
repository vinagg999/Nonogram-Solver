#include<bits/stdc++.h>

using namespace std;

// some predefined values
#define pb push_back
#define mp make_pair
#define ii insert
#define ff first
#define ss second
#define ll long long int

//2= not know, 1= filled, 0=empty

// ornt=1= horizontal; 2=vertical

int grid[60][60];
int dim;
bool check=true;


// Initial Leftmost Solver 

vector<int> leftmost(vector<int> val,int sum)
{
  vector<int> lm;
  for(int i=1;i<=val.size();i++)
  {
    for(int j=0;j<val[i-1];j++)
    lm.pb(i);
    lm.pb(0);
  }
  for(int i=0;i<dim-(sum+val.size()-1);i++)
    lm.pb(0);

  return lm;
}

// Initial Rightmost Solver

vector<int> rightmost(vector<int> val,int sum)
{
  vector<int> rm;
  for(int i=0;i<dim-(sum+val.size()-1);i++)
    rm.pb(0);
  for(int i=1;i<=val.size();i++)
  {
    for(int j=0;j<val[i-1];j++)
    rm.pb(i);
    rm.pb(0);
  }
  
 // reverse(rm.begin(),rm.end());
  return rm;
}

// Linesolver Function...Still in progress

void linesolver(vector<int> val, int ornt,int d)
{
  int sum=0;

  for(int i=0;i<val.size();i++)
    sum+=val[i];

cout<<sum<<endl;

  if(sum+val.size()-1>dim)
  {
    check=false;
    return;
  }

  vector<int> lm = leftmost(val,sum);
  vector<int> rm = rightmost(val,sum);

  for(int i=0;i<16;i++)
  cout<<lm[i];

cout<<endl; 
for(int i=0;i<16;i++)
  cout<<rm[i];
cout<<endl;
  vector<int> a;
  for(int i=0;i<dim;i++)
  a.pb(2);
  for(int i=0;i<dim;i++)
  {
    if(lm[i]==rm[i]&&lm[i]!=0)
    {
      a[i]=1;
      if(ornt==1)
      {
        grid[d][i]=1;
      }
      else
      {
        grid[i][d]=1;
      }
    }
  }
  for(int i=0;i<16;i++)
  cout<<a[i];

}


//  Simple Leftmost Solver

vector<int> leftmost(vector<int> val,int sum)
{
  vector<int> lm;
  for(int i=1;i<=val.size();i++)
  {
    for(int j=0;j<val[i-1];j++)
    lm.pb(i);
    lm.pb(0);
  }
  for(int i=0;i<dim-(sum+val.size()-1);i++)
    lm.pb(0);

  return lm;
}




// main function

int main()
{
  freopen("input.txt","r",stdin);

  cin>>dim;

  for(int i=0;i<dim;i++)
  {
    for(int j=0;j<dim;j++)
      grid[i][j]=2;
  }

  vector<int> val;
  for(int i=0;i<4;i++)
  {
    int a;
    cin>>a;
    val.pb(a);
  }
  
 /* for(int i=0;i<dim;i++)
  {
    for(int j=0;j<dim;j++)
     nano[i][j]=a;
  }
*/
  linesolver(val,1,0);
 /* for(int i=0;i<14;i++)
  {
    cout<<grid[0][i];
  }
  */
  return 0;
}