// 虽然课程已经进行到需要动用指针知识的时候了，
// 但是某傻喵(才不傻w)还是向偷个懒再对付一把。。
// 于是。。。

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	
	int k, l, t;
	
	cin >> k;
	
	while (k > 0) {
		
		int m, n, i, j;
		int sum = 0;
		
		cin >> m >> n;
		
		for (i = 0; i < m; i++) 
		{
			for (j = 0; j < n; j++) 
			{
				cin >> t;
				
				if (i == 0 || i == m-1 || j == 0 || j == n - 1) {
					sum += t;
				}
			}
		}
		
		cout << sum << endl;
		k--;
	}
	return 0;
}