// 15ms	1.085MB

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_N = int(1e3) + 10;

int cnt[MAX_N];
int main() {
	int n;
	while ( cin >> n ) {
		memset(cnt, 0, sizeof cnt);
		while ( n-- ) {
			int tmp; cin >> tmp;
			printf("%d%c", ++cnt[tmp], n?' ':'\n');
		}
	}
}