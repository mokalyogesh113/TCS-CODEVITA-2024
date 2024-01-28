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
    string line;
    vector<vector<string>> v;

    while(getline(cin , line))
    {
        vector<string> words;
        stringstream ss(line);
        string x;
        while(getline(ss , x , ' '))
        {
            words.pb(x);
        }
        v.pb(words);
    }

    int n = v.size();
    int tmp = v.back().size();
    map<string , int> mp;

    for(int i=0;i<tmp;i++)
    {
        mp[v[n-2][i]] = stoi(v[n-1][i]);
    }

    int cnt = 0;
    bool skip = false;
    vi ans;

    for(int i=0;i<n-2;i++)
    {
        if(skip)
        {
            if(v[i][0]=="is")
                cnt++;
            if(v[i][0]=="si")
            {
                if(cnt==0)
                {
                    skip = false;
                    continue;
                }
                cnt--;
            }
            if(cnt==0 && v[i][0]=="No")
            {
                skip = false;
                continue;
            }            
            continue;
        }

    
        if(v[i][0] == "is")
        {
            string exp = v[i][1];
            int exp_size = exp.size();

            string var1 = "", cond="", var2 = "";
            var1 +=  exp.substr(0,1);
            cond += exp.substr(1,exp_size-2);
            var2 += exp.substr(exp_size-1 , 1);


            switch(cond[0])
            {
                case '<':
                    if(mp[var1] < mp[var2])
                    {
                        continue;
                    }
                    else
                    {
                        skip = true;
                        continue;
                    }
                break;
                case '>':
                    if(mp[var1] > mp[var2])
                    {
                        continue;
                    }
                    else
                    {
                        skip = true;
                        continue;
                    }
                break;
                case '=':
                    if(mp[var1] == mp[var2])
                    {
                        continue;
                    }
                    else
                    {
                        skip = true;
                        continue;
                    }
                break;
                case '!':
                    if(mp[var1] != mp[var2])
                    {
                        continue;
                    }
                    else
                    {
                        skip = true;
                        continue;
                    }
                break;
            }
        }
        else if(v[i][0] == "Yes")
        {
            continue;
        }
        else if(v[i][0] == "print")
        {
            ans.pb(mp[v[i][1]]);
        }
        else if(v[i][0] == "No")
        {
            skip = true;
            continue;
        }   
        else if(v[i][0] == "si")
        {
            continue;
        }
    }



    int x = ans.size();
    for(int i=0;i<x-1;i++)
    {
        cout<<ans[i]<<endl;
    }
    if(x>0)
        cout<<ans.back();


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

