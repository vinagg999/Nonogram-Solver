
// FINAL-LEFTMOST SOLVER PART-1 !!!

#include<bits/stdc++.h>
 
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
int a[100005];
int n;
int b[100005];
vector<int> query;
pair<int,int> start_end[1000];
int q,flag=1;  



void initial()
{
  for(int i=0;i<n;i++){
      cin>>a[i];
   }
}

void simplesol(int l1, int r1, int q1)
{
  vector<int> filled;
   vector<int> empty;
   
   
   for(int i=l1;i<r1;i++){
    if(a[i]==4)empty.pb(i); // position of empty blocks
    if(a[i]==1)filled.pb(i); // position of filled blocks
   }

   int k=l1;  // index of array 
   int l=q1;  // index of the clues
   int total=query.size();

   while(k<r1&&l<total){  // while we reach the end of array of the or all the clues are used
    int x=query[l];
    int check=1;
    //cout<<k<<endl;
    for(int i=k;i<k+x;i++){
        if(a[i]==1||b[i]==3){
            check=0;
            break;
        }

    }

    if(k+x<r1){
        if(a[k+x]==4)  // if the element just after the block is filled we can't place the block
        check=0;
    }
    if(k>l1){
        if(a[k-1]==4)check=0;   // if the element just before the bolck is filled we can't place the block
    }
    if(check==1){
        //cout<<k<<endl;
        for(int i=k;i<k+x;i++){
            //if(b[i]!=4)
            b[i]=3;  // it is the left most solution
        }
        k+=x;       // move to next of next cell

    }
    k++;
    if(check==1)  // if check==1 we move to the next clue;
    l++;            
   }


}

void inputquery()
{
   for(int i=0;i<q;i++){
    int x;
    cin>>x;
    query.pb(x);
   }
}

vector<int> assign(int l1,int r1)
{
   vector<int> assigned;
   for(int i=l1;i<r1;i++){
    if(b[i]!=3&&a[i]==4){
      assigned.pb(i);
    }
   }
   return assigned;
}


void startend()
{
  int idx=0;
  int i=0;
  while(i<n){
    if(b[i]==3){
        start_end[idx].fi=i;
        i++;
        while(b[i]==3){
            i++;
        }
        i--;
        start_end[idx].se=i;
        //cout<<start_end[idx].fi<<" "<<start_end[idx].se<<endl;
        idx++;
    }
    i++;
  }

}


void final_output()
{
  for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
   }
}

int getblock(int pos,int j)
{
  for(int i=j;i>=0;i--)
  {
    if(start_end[i].second<pos)
      return i;
  }
  return -1;
}

void reposition(int x, int s)
{
  
}

int firstpart(int pos,int x,int rep)
{
      int l,r;

      l=start_end[x].fi;
      r=start_end[x].se;

      int tempx=l;
      int tempy=r;
      //cout<<tempx<<" "<<tempy<<endl;
      int done=0;

      // bolck just to the right of unassigned solid
      

        l+=pos-r;
        r=pos;

        // while the block overlaps the solid
        while(l<=pos&&r>=pos){
          
          int chk=1;

          // not a valid position if empty cell lies
          for(int i=l;i<r;i++){
            if(a[i]==1){
              chk=0;
              break;
            }
          }

          // not a valid position if another block is adjacent
          if(a[l-1]==3||a[l-1]==4||a[r+1]==3||a[r+1]==4){
            chk=0;
          }
          // if invalid position then move the block
          if(chk==0){
            l++;
            r++;
            continue;
          }
          // if valid position the mark all the unassigned solids in this range as solid
          if(chk==1)
          {
            done=1;

            // removing the old block
            for(int i=tempx;i<=tempy;i++)b[i]=0;

            // removing the earlier assigned blocks
            for(int i=tempx;i<=tempy;i++){
              if(a[i]==4)assigned.pb(i);
            }

            
           // for(int i=tempx;i<=tempy;i++){
             // if(a[i]==4)assigned.pb();
            //}

            // adding the new block
            for(int i=l;i<=r;i++)
              b[i]=3;

            if(r+1<n)
              b[r+1]=1;

            if(rep==1)
              reposition(x,r+1);

              break;
          }

        }
  return done;
}

void checker()
{
    int y=query.size()-1;
    while(assigned.size()!=0)
    {


     int pos=assigned[assigned.size()-1];
     //cout<< pos<<endl;
     assigned.pop_back();
     //assigned.pop();

      // block is already assigned
      if(b[pos]==3){
        continue;
      }
      // rightmost unassigned solid
      int y=getblock(pos,y);
      if(y==-1)
      {
        flag=0;
        return;
      }
      int x=firstpart(pos,y,0);
      
      if(x==1)
        {
          y--;
          break;
         } 
      else
      {
        int chk=0;
        while(y>0&&x!=1)
        {
          y--;
          x=firstpart(pos,y,1);
          if(x==1)
            {
              chk=1;
              break;
            } 
        }
        if(chk)
          continue;
        else
        {
          flag=0;
          break;
        }

      }
   }
   
}

void printsimplesol()
{
  for(int i=0;i<n;i++)
    cout<<b[i]<<" ";
  cout<<endl;
}

// 0 - dont know
// 1 - empty
// 3 - leftmost solution
// 4 - filled

int main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   freopen("input.txt","r",stdin);
   
   // run SIMPLE-LEFTMOST SOLVER
   //vector<int> arr=sipleLeftSolver();

   cin>>n;
   cin>>q;

   inputquery(); // l se r ki zaroorat shayad na ho
   initial();   // l se r ki zaroorat shayad na ho
   simplesol(l1,r1,q1); // starting from array index l1 upto r1 and q1 denotes the query from which it will start running
   vector<int> assign_block;
   assign_block = assign(l1,r1); // to get the assigned blocks in the range l1 to r1
   printsimplesol();
   startend();
   checker();
   final_output();

   return 0;
}