#include <string.h>
#include <stdio.h>

// #include <iostream>
// using namespace std;

const int MAX_LEN = 300;
const int ALPHA = 30;
const int NO_PARA = 1;
const int HAS_PARA = 2;
const int ERROR = 0x3f3f3f3f;
bool isalpha(char c) {
	return c >= 'a' && c <= 'z';
}

int para[ALPHA];
int ans[ALPHA];
char ansstr[ALPHA][MAX_LEN];
char in[MAX_LEN];
int previous_char;
int option(char tok[], int tokp) {
	int ret = -1;
	if (2 == tokp && 
		'-' == tok[0] && 
		isalpha(tok[1])) {
		int cc = tok[1] - 'a';
		if (NO_PARA == para[cc]) 
			ans[cc] = 1, ret = 0;
		else if (HAS_PARA == para[cc])
			previous_char = cc, ret = 1;
		else ret = ERROR;
	}
	return ret;
}
int main() {
	memset(para, false, sizeof para);
	scanf("%s", in);
	int len = strlen(in);
	char lastest = 'a';
	for(int i = 0; i < len; i++) {
		if (isalpha(in[i])) 
			lastest = in[i], 
			para[lastest - 'a'] = NO_PARA;
		else para[lastest - 'a'] = HAS_PARA;
	}
	
	//for(int i = 0; i < 26; i++) cout << char('a' + i) << "\t" << para[i] << endl;
	int tcase; scanf("%d", &tcase); gets(in);
	int ttcase = 0;
	while( tcase-- ) {
		memset(ans, 0, sizeof ans);
		gets(in);
		int len = strlen(in);
		char tok[MAX_LEN]; int tokp = 0;
		bool first = true;
		int next_para = 0;
		for (int inp = 0; inp <= len; inp++) {
			if (' ' == in[inp] || 
				'\t' == in[inp] || 
				'\n' == in[inp] ||
				'\0' == in[inp]) {
				if (0 != tokp) {
					tok[tokp] = 0;
					if(first) first = false;
					else {
						// printf("%s\n", tok);
						if(0 == next_para)
							next_para = option(tok, tokp);
						else if (1 == next_para) {
							next_para = 0;
							strcpy(ansstr[previous_char], tok);
							ans[previous_char] = 1;
						}
					}
					tokp = 0;
				}
			} else {
				tok[tokp++] = in[inp];
			}
		}
		printf("Case %d:", ++ttcase);
		for (int i = 0; i < ALPHA; i++) {
			if (NO_PARA == para[i] && 
				ans[i]) printf(" -%c", i + 'a');
			else if (HAS_PARA == para[i] &&
				ans[i]) printf(" -%c %s", i + 'a', ansstr[i]);
		}
		puts("");
	}
}