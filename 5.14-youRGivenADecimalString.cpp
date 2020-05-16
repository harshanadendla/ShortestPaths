//wow...bavundi

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template<size_t>
struct debug{};

template <class T>
ostream& print_tuple(ostream& out, const T& t, debug<1> ) {
    return out << get<tuple_size<T>::value-1>(t);
}

template <class T, size_t idx>
ostream& print_tuple(ostream& out, const T& t, debug<idx> ) {
    out << get< tuple_size<T>::value-idx >(t) << " , ";
    return print_tuple(out, t, debug<idx-1>());
}

template <class... Args>
ostream& operator<<(ostream& out, const tuple<Args...>& t) {
    out << "\n[";
    print_tuple(out, t, debug<sizeof...(Args)>());
    return out << "]\n";
}

template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define dbg(x) cerr<<x<<"\n"
#define bug(x) cout<<"hi"<<x<<endl

const int N=1e5+5;
const int mod=1e9+7;

int Madd(int a,int b) {
    return ((a%mod)+(b%mod)+mod)%mod;
}

int Mmull(int a,int b) {
    return ((a%mod)*(b%mod)+mod)%mod;
}

//#define test_cases

string str;
int ans[10][10];
int dp[10][10];

int go(int x,int y) {
	if (x>y) swap(x,y);
	if (ans[x][y] != -2) return ans[x][y];
	
	for (int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			dp[i][j]=mod;
		}
	}
	
	for (int i=0;i<10;i++) {
		dp[i][(i+x)%10]=0;
		dp[i][(i+y)%10]=0;
	}
	
	for (int k=0;k<10;k++) {
		for (int i=0;i<10;i++) {
			for (int j=0;j<10;j++) {
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+1);
			}
		}
	}
	
	int res=0;
	for (int i=1;i<(int)str.size();i++) {
		res+=dp[str[i-1]-'0'][str[i]-'0'];
	}
	
	if(res<mod) return ans[x][y]=res;
	return ans[x][y]=-1;
}

void solve() {
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			ans[i][j]=-2;
		}
	}	
	cin>>str;
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			cout<<go(i,j)<<" ";
		}
		cout<<endl;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    int t=1;
#ifdef test_cases
    cin>>t;
#endif
    while(t--) {
        solve();
    }
    return 0;
}