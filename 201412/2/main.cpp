// 109ms	2.234MB

#include <string.h>
#include <stdio.h>

#include <iostream>
using namespace std;

const int MAX_N = 550;
const int evenx = -1;
const int eveny = +1;
const int oddx = +1;
const int oddy = -1;

int mp[MAX_N][MAX_N], n; 
bool in(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &mp[i][j]);

	bool even = true;
	for (int i = 0; i < 2 * n - 1; i++) {
		if ( i < n ) {
			int x = i, y = 0;
			if (!even) x = 0, y = i;
			while (true) {
				if ( !in(x, y) ) break;
				printf("%d ", mp[x][y]);
				if (even) {
					x += evenx; y += eveny;
				} else {
					x +=oddx; y += oddy;
				}
			}
		} else {
			int x = i % n + 1, y = n - 1;
			if (even) x = n - 1, y = i % n + 1;
			
			// printf("\nx: y: %d %d\n", x, y);
			while (true) {
				if ( !in(x, y) ) break;
				printf("%d%c", mp[x][y], i==2 * n - 2?'\n':' ');
				if (even) {
					x += evenx; y += eveny;
				} else {
					x +=oddx; y += oddy;
				}
			}
		}
		even ^= true;
	}
}