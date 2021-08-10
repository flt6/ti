#include <bits/stdc++.h>
using namespace std;

int n,m,s;
int head[10010],nxt[500010],to[500010],v[500010];
int dis[10010],vis[10010];

void dijk(){
    memset(dis,0x7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int minp;
    dis[s]=0;
    for (int i=1;i<=n;i++){// i: only for count
        minp=0;
        for (int j=1;j<=n;j++)
            if (!vis[j]&&dis[minp]>dis[j])
                minp=j;
        if (minp==0) break;
        vis[minp]=true;
        for (int j=head[minp];j!=0;j=nxt[j]){//遍历以minp的所有出边
            int top=to[j];//表示第j号边是(minp)->(top)的
            int tmp=dis[minp]+v[j];
            if (!vis[top]&&dis[top]>tmp)
                dis[top]=tmp;
        }
    }
}

int main(){
    cin>>n>>m>>s;
    int x,y,z;
    for (int i=1;i<=m;i++){
        cin>>x>>y>>z;
        nxt[i]=head[x];
        head[x]=i;
        to[i]=y;
        v[i]=z;
    }
    dijk();
    for (int i=1;i<=n;i++){
        if (vis[i]) printf("%d ",dis[i]);
        else cout<<2147483647<<" ";
    }
    return 0;
}