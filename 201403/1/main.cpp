//15ms	6.343MB

#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N = int(1e3) + 10;
bool pos[MAX_N], neg[MAX_N];

int main() {
	int n;

	while( cin >> n ) {
		memset(pos, false, sizeof pos);
		memset(neg, false, sizeof neg);
		while( n-- ) {
			int tmp; cin >> tmp;
			if (tmp < 0) neg[-tmp] = true;
			else pos[tmp] = true;
		}

		int ans = 0;
		for (int i = 1; i < MAX_N; i++) if(pos[i] && neg[i])
			ans++;
		cout << ans << endl;
	}
}