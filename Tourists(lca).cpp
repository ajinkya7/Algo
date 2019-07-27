#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define SUBL freopen("/home/ajinkya/Desktop/input.txt","r",stdin); freopen("/home/ajinkya/Desktop/output.txt","w",stdout); 
#define ll long long
#define ull unsigned long long
#define FI(i,a,n) for(int i=a; i<=n; i++)
#define RFI(i,n,a) for(int i=n; i>=a; i--)
#define FLL(i,a,n) for(ll i=a; i<=n; i++)
#define RFLL(i,n,a) for(ll i=n; i>=a; i--)
#define vi vector<int>
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pi pair<int, int>
#define GCD(a,b) __gcd(a,b)
#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define debug(x) cout << x << endl
#define MOD 1000000007
#define INF LLONG_MAX
#define PI 3.14159265359
using namespace std;

int n;
vector<int> adj[200005];
int p[20][2000005];
int d[200005];

void dfs(int u, int par)
{
    for(auto v:adj[u])
    {
        if(v==par) continue;
        d[v] = d[u] + 1;
        p[0][v] = u;
        dfs(v,u);
    }
}

void gen_parent()
{
    for(int i=0; i<19; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(p[i][j] != -1)
            {
                p[i+1][j] = p[i][p[i][j]];
            }
        }
    }
}

int lca(int u, int v)
{
    if(d[u] > d[v]) swap(u,v);
    if(d[u]<d[v])
    {
        for(int j=19;j>=0;j--)
        {
            if(d[v] - (1<<j) >= d[u])
            {
                v = p[j][v];
            }
        }
    }
    if(u==v) return u;
    for(int j=19; j>=0; j--)
    {
        if(p[j][u]!=p[j][v])
        {
            u = p[j][u];
            v = p[j][v];
        }
    }
    return p[0][u];
}

int dist(int u, int v)
{
    return d[u] + d[v] - 2*d[lca(u,v)] + 1;
}

int main()
{
    fastio 
    // SUBL
    memset(p,-1,sizeof p);
    cin >> n;
    FI(i,1,n-1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    d[1] = 0;
    dfs(1,-1);
    gen_parent();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            ans += dist(i,j);
        }
    }
    cout << ans;
    return 0;
} 
