#include <bits/stdc++.h>

#include <random>

using namespace std;
#define int long long
#define LL long long
#define int long long
#define YES "YES"
#define NO "NO"
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
typedef __uint128_t ulll;
typedef pair<int, int> pii;
typedef long long i64;
const double eps = 1e-9;
const int N = 3e6 + 10;
const int INF = 1e18;
const int mod = 1e9 + 7;
const int base = 13331;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int dx[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void generate() {
    std::random_device rd;  // 使用硬件生成真随机数种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
    std::uniform_int_distribution<int> dist(1, 1e18); // 在1到100之间均匀分布的整数
    // 生成真随机数
    int n = dist(gen) % (int) (1e5) + 1,m = dist(gen) % (int) (1e8) + 2;
    //cout<<n<<" "<<m<<endl;
    cout << dist(gen) % (int) (127) +1<<" ";
    cout << dist(gen) % (int) (127) +1<<" ";
    cout << dist(gen) % (int) (127) +1;
}



void solve() {

}

signed main() {
    //出输入
   for(int i=1;i<=10;i++) {
       string in="F:/Clion/DayTest/inAndout/"+ to_string(i)+".in";
       freopen(in.c_str(), "w", stdout);
       generate();
   }
    //出输出
    int x = 10;
    for (int i = x; i <= x; i++) {
        string in = "F:/Clion/DayTest/inAndout/" + to_string(i) + ".in";
        string out = "F:/Clion/DayTest/inAndout/" + to_string(i) + ".out";
        freopen(in.c_str(), "r", stdin);
        freopen(out.c_str(), "w", stdout);

        //---------------------------------------

        int T = 1;
//        cin>>T;
        while (T--)
            solve();

        //-------------------------------------------


    }
}