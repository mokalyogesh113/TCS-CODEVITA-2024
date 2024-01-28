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
// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

using namespace std;


int dijkstra(vvi &adj, int s , int d)
{

    int n = adj.size();
    vi vis(n,0);
    queue<pii> q;


    q.push({s , 0});
    vis[s] = 1;
    while(!q.empty())
    {
        pii node = q.front();
        q.pop();


        if(node.first==d)
        {
            return node.second;
        }

        for(auto i:adj[node.first])
        {
            if(!vis[i]){
                vis[i] = 1;
                q.push({i , node.second+1});
            }
        }
    }

    return -1;
}


void solve()
{
    string S ;
    getline(cin,S);
    stringstream ss(S);

    int n;
    ss>>n;

    vvi adj(n);

    for(int i=0 ; i<n;i++)
    {
        getline(cin,S);
        stringstream ss(S);
        int x;
        while(ss>>x)
        {
            adj[i].push_back(x-1);
        }
    }
    int s,d;
    cin>>s>>d;
    s--,d--;
    

    // for(auto i:adj){for(auto j:i) cout<<j<<" "; cout<<endl;}

    // cout<<s<<d<<endl;

    int ans = dijkstra(adj ,s , d );
    cout<<ans;

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

