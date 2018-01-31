#include <bits/stdc++.h>

using namespace std;

int f, src, dest, up, down, moves;
int vis[1000001];
int dist[1000001];

void bfs()
{
    int cur, nextUp, nextDown;
    queue<int> q;
    vis[src] = 1;
    dist[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        nextUp = cur + up;
        nextDown = cur - down;
        if(nextUp<=f && !vis[nextUp])
        {
            vis[nextUp] = 1;
            dist[nextUp] = dist[cur]  + 1;
            q.push(nextUp);
        }
        if(nextDown>=1 && !vis[nextDown])
        {
            vis[nextDown] = 1;
            dist[nextDown] = dist[cur]  + 1;
            q.push(nextDown);
        }
    }
}

int main()
{
    cin>>f>>src>>dest>>up>>down;
    
    dist[dest] = -1;
    bfs();
    if(dist[dest] == -1)
    {
        cout<<"use the stairs";
    }
    else
    {
        cout<<dist[dest];
    }

}