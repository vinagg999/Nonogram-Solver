
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
 
//vector<list<int>> v;
//ll b[200005];
//ll a[300005],b[300005],c[300005];
//ll a[1001005];
//pair<int,int> a[1000005];
//vector<ll> l;
//pair<int,int>p;
//pair<ll,int> a[500005];
//vector<int> adj[100005];
//unordered_set<int> s;

bool comp(const int a,const int b){
    return a<b;
}
 
bool RelativelyPrime (int a, int b) { 
   return (a<b) ? RelativelyPrime(b,a) : !(a%b) ? (b==1) : RelativelyPrime (b, a%b);
}

int a[100005];
int n;
int b[100005];
vector<int> query;
vector<int> assigned;
pair<int,int> start_end[1000];
int q;  


void initial()
{
  for(int i=0;i<n;i++){
      cin>>a[i];
   }
}

void simplesol()
{
  vector<int> filled;
   vector<int> empty;
   
   
   for(int i=0;i<n;i++){
    if(a[i]==4)empty.pb(i); // position of empty blocks
    if(a[i]==1)filled.pb(i); // position of fillde blocks
   }

   int k=0;  // index of array 
   int l=0;  // index of the clues
   int total=query.size();

   while(k<n&&l<total){  // while we reach the end of array of the or all the clues are used
    int x=query[l];
    int check=1;
    //cout<<k<<endl;
    for(int i=k;i<k+x;i++){
        if(a[i]==1||b[i]==3){
            check=0;
            break;
        }

    }

    if(k+x<n){
        if(a[k+x]==4)  // if the element just after the block is filled we can't place the block
        check=0;
    }
    if(k>0){
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

void assign()
{
   for(int i=0;i<n;i++){
    if(b[i]!=3&&a[i]==4){
      assigned.pb(i);
    }
   }
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

void checker()
{

    while(assigned.size()!=0){


     int pos=assigned[assigned.size()-1];
     //cout<< pos<<endl;
     assigned.pop_back();
     //assigned.pop();

      // block is already assigned
      if(b[pos]==3){
        continue;
      }
      // rightmost unassigned solid
     
      int l,r;
      for(int i=q-1;i>=0;i--){

     

        l=start_end[i].fi;
        r=start_end[i].se;

        int tempx=l;
        int tempy=r;
        //cout<<tempx<<" "<<tempy<<endl;
        int done=0;

        // bolck just to the right of unassigned solid
        if(r<pos){

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
            if(chk==1){
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
              for(int i=l;i<=r;i++)b[i]=3;

                break;
            }

          }
          if(done==1){
            break;

          }
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

   inputquery();
   initial();
   simplesol();
   assign();
   printsimplesol();
   startend();
   checker();
   final_output();

   return 0;
}