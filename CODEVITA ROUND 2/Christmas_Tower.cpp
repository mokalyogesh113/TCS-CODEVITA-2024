//Code By @trickymindme
#include<bits/stdc++.h>
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
#define vvi vector<vi>
#define vvl vector<vll>
#define vs vector<string>
#define  pii pair<int,int>
#define mpii map<int,int>
#define mem(a,b) memset(a,(b),sizeof(a))
#define FOR(i,j,k,in) for(int i=j;i<k;i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i,j) FOR(i,0,j,1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(c) (c).begin(),(c).end()
#define scanArray(v) for(auto &i:v) cin>>i;
#define printArray(v) for(auto &i:v) cout<<i<<" "; cout<<endl;
#define MP make_pair
#define pb push_back
#define eb emplace_back
#define INF (int)1e9
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

#define _test() int _T;  cin>>_T; while(_T--)
#define _test2() for(int c=1;c<T+1; c++){  cout<<"Case #"<<c<<": "; solve();}
#define _print_time() cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC  << " mS\n"

// Functions
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

using namespace std;

int n=5;

bool f1(vi &v , vi &freq , int h , vvi &dp)
{
    if(h<0) return false;
    if(h==0)    return true;


    for(int i=0;i<n;i++)
    {
        if(dp[i][h]!=-1)
            if(dp[i][h] == 1)   return true;
            else    continue;
            
        if(f1(v , freq , h - v[i] ,dp ))
        {
            freq[i]++;
            return dp[i][h] = 1;
        }
        dp[i][h] = 0;
    }
    return false;
}

void solve()
{
    int h;
    cin>>h;

    vi v(5);
    scanArray(v);

    sort(all(v));
    vi freq(5,0);
    
    // printArray(v);

    // return ;
    vvi dp(5 , vi(h+1,-1));

    if(f1(v,  freq , h , dp))
    {
        
        vector<pii> p;
        for(int i=0;i<n;i++)
        {  
            p.push_back({v[i] , freq[i]});
        }
        sort(all(p) , [&](auto &a , auto &b){
            
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        vi ans;
        for(auto i:p)
        {
            if(i.second==0)
                break;
            ans.pb(i.first);
        }

        int x = ans.size();
        for(int i=0;i<x-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans.back();
        
        return;

    }

    cout<<"Impossible";



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // _test() 
        solve();
        
    // _print_time();
    return 0;    
}

