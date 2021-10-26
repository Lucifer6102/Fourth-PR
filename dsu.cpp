#include <bits/stdc++.h>
#define ll long long  int
#define N 300000
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define pp pair<ll,ll>
#define lb lower_bound
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(),x.end()
#define PI 3.14159265
#define cot cout.tie(0)
using namespace std;
/**
* @author :: Rishabh
*
*
**/
 void initialize(ll a[],ll size[],ll n)//initializing dsu each vertex is parent of itself
{
      f(i,1,n)
       {
      a[i]=i;
      size[i]=1;
       }
}
// This dp technique is also known as path compression
/*
ll root(int x)
{
  if(x==parent[x])
  return x;

  else
   return parent[x]=root(parent[x]);

   // Here parent is a[]; 
}
*/
ll root(ll a[],ll i)
{
  while(a[i]!=i)
  {
    a[i]=a[a[i]];
    i=a[i];
  }
  return i;
}
bool find(ll x,ll y,ll a[])
{
  if(root(a,x)==root(a,y))
    return true;
  else
    return false;
}
void wieghted_union(ll a[],ll size[],ll x,ll y) // union by id
{
   ll rootX=root(a,x);
   ll rootY=root(a,y);
   if(find(x,y,a))
    return ;

   if(size[rootX]<size[rootY])
   {
     size[rootY]+=size[rootX];
     a[rootX]=a[rootY];
   }
   else
   {
     size[rootX]+=size[rootY];
     a[rootY]=a[rootX];
   }
}

  int main()
 {
  ibs;
  cti;
  ll n,m;
  cin >> n >> m;
  ll a[n+1]={0};
  ll size[n+1]={0};
    initialize(a,size,n);
  f(i,1,m)
  {
    ll x,y;
    cin >> x >> y;
    wieghted_union(a,size,x,y);
  }
  ll cnt=0;

  // To count the number of connected components

  f(i,1,n)
  {
    if(a[i]=i)
      cnt++;
   }

   // To find the number of ways in which cities can be chosen

  f(i,1,n)
  {
    int x=root(a,i);
    cnt=cnt+(n-size[x]);
  }
   cout << cnt/2 << endl;
   return 0;
 }

// Time complexity : O(m)