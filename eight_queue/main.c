#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>




int c[20], n = 8, cnt = 0;
void print() {
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (j == c[i]) printf("1");
			else printf("0");
		}
		//cout << endl;
		printf("\n");
	}
	//cout << endl;
	printf("\n");
}
void search(int r) {
	if (r == n) {
		print();
		++cnt;
		return;
	}
	for (int i = 0; i<n; ++i) {//遍历列
		c[r] = i; //第r行放在第i列
		int ok = 1;
		for (int j = 0; j<r; ++j) //向上检查这个点能不能放
			if (c[r] == c[j] || r - j == c[r] - c[j] || r - j == c[j] - c[r]) {
				ok = 0;
				break;
			}
		if (ok) search(r + 1); //能放则看下一行
	}
}
int main() {
	search(0);
	//cout << cnt << endl;
	printf("%d", cnt);
	getchar();
	return 0;
}


/*

int main()
{
	bool d = isMatch("aab", "c*a*b");



	printf("%d\n", d);
	getchar();

	return 0;
}
*/