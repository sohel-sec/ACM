#include <bits/stdc++.h>
using namespace std;

template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p){return os << "(" << p.first << "," << p.second << ")";}
ostream& operator<<(ostream &os, const string& t){for(auto it=t.begin(); it!=t.end(); it++)os << *it;return os;}
template<typename T> auto operator<<(ostream& os, const T& t)-> typename conditional<true, ostream&, decltype(*t.begin())>::type{ os << "["; for(auto it=t.begin(); it!=t.end(); it++){if(it != t.begin()) os << ",";os << *it;} os << "]"; return os; }
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){cerr << ' ' << H;dbg_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef vector<int> vi;


int main(){
    ios::sync_with_stdio(false); cin.tie(0);




	return 0;
}



