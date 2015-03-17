// 0ms	1.007MB

#include <stdio.h>
#include <string.h>

const int MAX_LEN = 200;

char key[MAX_LEN], in[MAX_LEN];
bool match(int case_sensitive, char a, char b) {
	if (a == b) return true;
	if (case_sensitive == 0 && 
		(a - b == 32 || b - a == 32)) return true;
	return false;
}
bool contains(int case_sensitive) {
	int keylen = strlen(key);
	int inlen = strlen(in);
	bool yes = true;
	for (int i = 0; i + keylen <= inlen; i++) {
		yes = true;
		for (int j = 0; j < keylen; j++) {
			if (!match(case_sensitive, in[i + j], key[j])) {
				yes = false;
			}
		}
		if (yes) return true;
	}
	return false;
}
int main() {
	// printf("%d\n", match(1, 'H', 'h'));
	while(scanf("%s", key) != EOF) {
		int case_sensitive; scanf("%d", &case_sensitive);
		int tcase; scanf("%d", &tcase);
		while ( tcase-- ) {
			scanf("%s", in);
			if(contains(case_sensitive)) puts(in);
		}
	}
}