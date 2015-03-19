// 109ms	2.160MB
// 最小生成树+并查集

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_E = int(1e5) + 10;
const int MAX_N = int(1e3) + 10;

struct edge {
	int from, to, cost;
	void init() { scanf("%d%d%d", &from, &to, &cost); from--, to--;}
} ed[MAX_E]; int edp;

bool cmp ( const edge &a, const edge &b ) {
	return a.cost < b.cost;
}


// 注意并查集的写法，记得要判断重复
int fa[MAX_N];
int find ( int x ) {
	if (fa[x] == x) return x;
	else fa[x] = find(fa[x]);
	return fa[x];
}

bool uni ( int from, int to ) {
	int x = find(from);
	int y = find(to);
	if (x == y) return false;
	fa[y] = x;
	return true;
}

int n, m;
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) fa[i] = i;
		edp = m;
		for (int i = 0; i < edp; i++) 
			ed[i].init();
		sort(ed, ed + edp, cmp);
		int ans = 0;
		for (int i = 0; i < edp; i++) {
			int from = ed[i].from, to = ed[i].to;
			if (!uni(from, to)) continue;
			ans += ed[i].cost;
		}
		printf("%d\n", ans);
	}
}