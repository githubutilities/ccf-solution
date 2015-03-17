#include <stdio.h>
#include <string.h>

const int MAX_VAL = int(1e4) + 10;
int cnt[MAX_VAL];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(cnt, 0, sizeof cnt);
		while( n-- ) {
			int tmp; scanf("%d", &tmp); cnt[tmp]++;
		}

		int ans = 0;
		for (int i = 1; i < MAX_VAL; i++) 
			if (0 != cnt[i - 1] && 0 != cnt[i]) 
				ans++;
		printf("%d\n", ans);
	}
}