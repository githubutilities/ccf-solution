// 0ms	1.007MB
#include <string.h>
#include <stdio.h>

const int MAX_LEN = 50;

int main() {
	char in[MAX_LEN];
	int num[MAX_LEN], nump;

	while(scanf("%s", in) != EOF) {
		memset(num, 0, sizeof num); nump = 0;

		int len = strlen(in);
		for(int i = 0; i < len - 1; i++) if ('-' != in[i])
			num[nump++] = in[i] - '0';

		int sum = 0;
		for(int i = 0; i < nump; i++) 
			sum += num[i] * (i + 1);
		sum %= 11;

		if ((10 == sum && 'X' == in[len - 1]) ||
			sum + '0' == in[len - 1]) puts("Right");
		else {
			if( 10 == sum ) 
				in[len - 1] = 'X';
			else in[len - 1] = sum + '0';
			puts(in);
		}
	}

}