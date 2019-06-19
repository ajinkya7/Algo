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
#define PI 3.14159265
using namespace std;

int n, q;
int trie[1000006][26],node=0, weight[1000006];

void insert(string s, int wt)
{
	int t=0;
	for(int i=0; i<s.length(); i++)
	{
		if(trie[t][s[i]-'a']==0)
		{
			trie[t][s[i]-'a'] = ++node;
		}
		t = trie[t][s[i]-'a'];
		weight[t] = max(weight[t],wt);
	}
}

int query(string s)
{
	int t=0;
	for(int i=0; i<s.length(); i++)
	{
		if(trie[t][s[i]-'a']==0) return -1;
		t = trie[t][s[i]-'a'];
	}
	return weight[t];
}

int main()
{
	fastio
	// SUBL
	memset(trie,0,sizeof trie);
	cin >> n >> q;
	string s;
	int wt;
	FI(i,0,n-1) 
	{
		cin >> s >> wt;
		insert(s,wt);
	}
	FI(i,0,q-1)
	{
		string qr;
		cin >> qr;
		cout << query(qr) << "\n";
	}
	return 0;
}
