#include <bits/stdc++.h>
#define pii pair <int,int> // dat pair <int,int> thanh pii
using namespace std;

vector <pii> G[100004];
int n,m,s,t,d[100004],Trace[100004];
bool visited[100004];

void dijkstra(int s)
{
	for(int i = 1 ; i <= n ; i++) d[i] = 1e9; //luc dau cac khoang cach la vo cung

	priority_queue < pii , vector <pii> , greater <pii> > q;

	q.push({0,s}); //day dinh s vao queue voi khoang cach la 0
    d[s] = 0;

	while(!q.empty())
		{
			int u = q.top().second; q.pop();
			visited[u] = true;

			for(pii v:G[u])
				if(!visited[v.first] && d[v.first] > d[u] + v.second)
                {
                    d[v.first] = d[u] + v.second;
                    Trace[v.first] = u;
                    q.push({d[v.first],v.first});
                }
		}
}

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1 ; i <= m ; i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            G[a].push_back({b,w});
            G[b].push_back({a,w});
        }
    dijkstra(s);

    int tmp = t;
    while(tmp != s && tmp != -1)
    {
        cout << tmp << " ";
        tmp = Trace[tmp];
    }
    cout << s;

}
