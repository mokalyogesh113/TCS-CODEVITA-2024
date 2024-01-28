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

vvi generate(int x,int y,int x1,int y1)
{
    vvi ans;

    ans.push_back({x1 + y , y1 - x}); 
    ans.push_back({x1 - y , y1 + x}); 
    ans.push_back({x1 + x , y1 + y}); 
    ans.push_back({x1 -  x , y1 - y});
    return ans;
}

void solve()
{
    int m,n;
    cin>>m>>n;
    vvi board(m,vi(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }

    vi start(2) , end(2) , step(2);
    scanArray(start);
    scanArray(end);

    int x,y;
    cin>>x>>y;

    if(start == end)
    {
        cout<<0;
        return;
    }

    vvi distance(m , vi(n,-1));
    distance[start[0]][start[1]] = 0;

    queue<vi> q;
    q.push(start);
    
    while(!q.empty())
    {
        vi curr = q.front();    q.pop();
        int x1 = curr[0] , y1 = curr[1];
        int d = distance[x1][y1];

        // printArray(curr);


        if(curr == end)
        {
            cout<<distance[x1][y1];
            return;
        }
        
        // generating all possible combinations
        
        vvi positions = generate(x,y,x1,y1);
        for(auto i : positions)
        {
            if(i[0]>=0 && i[0]<n && i[1]>=0 && i[1]<n && board[i[0]][i[1]]==0 &&  distance[i[0]][i[1]] == -1)
            {
                q.push(i);
                distance[i[0]][i[1]] = d + 1;
            }
        }     
    }

    cout<<-1<<endl;

    
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

