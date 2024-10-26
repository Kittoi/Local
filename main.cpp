#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Rep(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
inline long long read()
{
    char c=getchar();long long x=0;bool f=0;
    while(!isdigit(c))f^=!(c^45),c=getchar();
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f)x=-x;return x;
}
// 定义常量，最大节点数和最大边数
const int maxn=100010;
const int maxm=200010;
// 边的结构体
struct edge{int next,v;long long w;}e[3*maxm];
// 用于存储每个数字是否已经存在于图中
map<long long,int>MP;
int head[maxn],cnt=0; // 头节点数组和边的计数器
long long n,dis[maxn],d,w;
int m,u,v,s,pos;
long long a[maxn],b[maxn];
long long p[maxm]; // 存储所有节点的数组
struct node
{
    int u; // 节点索引
    long long d; // 到该节点的距离
    // 优先队列中，比较两个node，距离大的优先级高
    bool operator <(const node& r) const{return d>r.d;}
};
node Q;

// 添加一条边
void add(int u,int v,long long w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
priority_queue<node>q; // 优先队列，用于Dijkstra算法
long long g,h,j,k;
// 计算对面数字的函数
long long finda(long long g)
{
    k=sqrt(g); // 计算平方根
    if(k%2==1) k--; // 如果是奇数，则对面数字需要减1
    if(g==4) return 1; // 特殊情况，4的对面是1
    if(g==k*k) return (k-2)*(k-2)+1; // 如果g是完全平方数，计算对面数字
    h=(g-k*k)/(k+1); // 计算h
    h*=2; // 乘以2
    j=(k-2)*(k-2)+(g-k*k-1)-h; // 计算对面数字
    return j;
}
int main()
{
    memset(dis,0x3f,sizeof dis); // 初始化距离数组为无穷大
    n=read();scanf("%d",&m); // 读取出口和倒塌墙的数量
    MP[1]=1;p[++pos]=1; // 起点1加入图中
    MP[n]=1;p[++pos]=n; // 终点n加入图中
    For(i,1,m)
    {
        a[i]=read();b[i]=finda(a[i]); // 读取倒塌墙的一侧数字，计算另一侧数字
        if(!MP[a[i]])
        {
            MP[a[i]]=1; // 如果a[i]不在图中，则加入
            p[++pos]=a[i];
        }
        if(!MP[b[i]])
        {
            MP[b[i]]=1; // 如果b[i]不在图中，则加入
            p[++pos]=b[i];
        }
    }
    sort(p+1,p+pos+1); // 对所有节点进行排序
    For(i,1,pos)
    {
        MP[p[i]]=i; // 更新MP映射
    }
    For(i,1,pos-1)
    {
        add(i,i+1,p[i+1]-p[i]); // 添加边，表示节点之间的距离
        add(i+1,i,p[i+1]-p[i]); // 因为是无向图，所以需要添加两条边
    }
    For(i,1,m)
    {
        add(MP[a[i]],MP[b[i]],1ll); // 倒塌的墙转化为边
        add(MP[b[i]],MP[a[i]],1ll);
    }
    dis[1]=0; // 起点到自己的距离为0
    q.push((node){1,0}); // 将起点加入优先队列
    while(!q.empty())
    {
        Q=q.top(); // 获取距离最小的节点
        q.pop();
        u=Q.u;d=Q.d;
        if(d!=dis[u]) // 如果这个距离不是最新的，跳过
            continue;
        for(int i=head[u];i;i=e[i].next) // 遍历所有邻接节点
        {
            v=e[i].v;w=e[i].w;
            if(dis[u]+w<dis[v]) // 如果新计算的距离更短
            {
                dis[v]=dis[u]+w; // 更新距离
                q.push((node){v,dis[v]}); // 将节点重新加入优先队列
            }
        }
    }
    printf("%lld",dis[MP[n]]); // 输出到终点的最短距离
}