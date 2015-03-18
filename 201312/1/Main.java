// 234ms	63.55MB

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	private static final int MAX_N = 10010;
	private static final Scanner scan = new Scanner(System.in);
	private static final PrintStream out = System.out;
	public static void main(String[] args) {
		int[] cnt = new int[MAX_N];
		while (scan.hasNext()) {
			int n = scan.nextInt();
			for (int i = 0; i < n; i++) {
				int tmp = scan.nextInt();
				cnt[tmp]++;
			}
			int ans = 0, mx = 0;
			for (int i = 1; i < MAX_N; i++) {
				if (mx < cnt[i]) {
					mx = cnt[i];
					ans = i;
				}
			}
			out.println(ans);
		}
	}

}