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
// to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

using namespace std;


int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


bool isLeap(int y)
{
    return (y%400==0 || (y%100!=0 && y%4==0));
}


int findDay(string date)
{
    int Y,m,d;
    Y = stoi(date.substr(0,4));
    m = stoi(date.substr(4,2));
    d = stoi(date.substr(6,2));
    int y = Y-1;


    int ans = 0;
    y = y % 400;

    int x = y/100;
    y = y%100;
    ans+= (x==1 ? 5 : x==2 ? 3 : x==3 ? 1 : 0);

    ans = (ans + y )%7;
    ans =(ans + (y/4) )%7;

    if(isLeap(Y)){
        days[1] = 29;
    }

    for(int i=0;i<m-1;i++)
    {
        ans = (ans + days[i] )% 7;
    }


    ans  = (ans + d ) %7;
    return ans;
}


// pair<int,pii> nextDate(int y,int m,int d,int x)
// {

//     int D = d+x;
//     int M = m;
//     int Y = y;

//     while(days[M] < D)
//     {

//     }


//     return {Y,{M,D}};
// }

void solve()
{

    map<string,int> wd;
    wd["Sun"] = 0;
    wd["Mon"] = 1;
    wd["Tue"] = 2;
    wd["Wed"] = 3;
    wd["Thu"] = 4;
    wd["Fri"] = 5;
    wd["Sat"] = 6;


    string date , day;
    ll n;
    cin>>date>>day>>n;

    int currDay  = findDay(date);

    int diff = (wd[day] + 7 - currDay) % 7;
    if(diff==0)
    {
        cout<<"No 0";
        return;
    }

    int y,m,d;
    y = stoi(date.substr(0,4));
    m = stoi(date.substr(4,2));
    d = stoi(date.substr(6,2));


    for(int x = diff;x<=146400;x)
    {   
        if(isLeap(y)){
            days[1] = 29;
        } else{
            days[1] = 28;
        }


        if(prime(x) && prime(m))
        {
            if(x>n) cout<<"No "<<x;
            else    cout<<"Yes "<<x;
            return;
        }

        if(!prime(m))
        {
            int temp = (((days[m-1] - d)/7)+1)*7;
            x+=temp;
            d+=temp;
        } else{
            d+=7;
            x+=7;
        }

        if(days[m-1]<d)
        {
            m++;
            d = d-days[m%12];
        }
        if(m>12)
        {
            m%=12;
            y++;
        } 
    }


    

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

