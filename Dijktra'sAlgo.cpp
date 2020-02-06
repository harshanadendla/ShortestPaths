#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define pb push_back
#define f first
#define s second
const int N=1e5;

int n,m,a,b,c;
vector<pair<int,int>> graph[N];
vector<int> dist(N);
priority_queue<pair<int,int>> pq;

void setMemory()
{
    for(int i=0;i<N;i++) dist[i]=INF;    
    for(auto i : graph) i.clear();
    pq=priority_queue<pair<int,int>>();
}

// pq lo emo....{wight,idx}.....graph lo emo {idx,wight}
// dist[0]=0 chala imp

void Dijkstra()
{
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        if(dist[p.s]<p.f) continue;
        int u=p.s;
        for(auto i : graph[u])
        {
            int v=i.f;
            int w=i.s;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    setMemory();
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a].pb(make_pair(b,c));
        graph[b].pb(make_pair(a,c));
    }
    Dijkstra();
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
    cout<<"\n";
    return 0;
}
