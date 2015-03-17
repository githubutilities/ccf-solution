// 15ms	6.718MB
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N = int(1e5) + 10;
int cnt[MAX_N];
int main() {
	int n;
	while (cin >> n) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			cnt[tmp]++;
		}
		int mx = 0, ans = 0;
		for (int i = 0; i < MAX_N; i++) if (cnt[i] > mx) {
			mx = cnt[i];
			ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}