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

void solve()
{
    int m,n;
    cin>>m>>n;

    vvi matrix(m , vi(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int sx,sy;
    int dx,dy;

    cin>>sx>>sy;
    cin>>dx>>dy;

    sx--,sy--;
    dx--,dy--;

    if(sx>dx || sy>dy)
    {
        cout<<-1;
        return;
    }

    vvi dp(m , vi(n,INT_MAX));
    dp[dx][dy] = matrix[dx][dy];

    for(int j=dy-1;j>=sy;j--)
    {
        int i = dx;
        dp[i][j] = dp[i][j+1] + matrix[i][j];
    }

    for(int i=dx-1;i>=sx;i--)
    {
        int j = dy;
        dp[i][j] = dp[i+1][j] + matrix[i][j];
    }

    for(int i=dx-1;i>=sx;i--)
    {
        for(int j=dy-1;j>=sy;j--)
        {
            dp[i][j] = min({dp[i][j+1] , dp[i+1][j]}) + matrix[i][j];
        }
    }

    cout<<dp[sx][sy];



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

