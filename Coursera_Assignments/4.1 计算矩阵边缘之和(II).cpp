// 虽然课程已经进行到需要动用指针知识的时候了，
// 但是指针也米有想象中那么那么难／

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	int k, l, t;
	
	// 一共有 k 组不同的输入
	cin >> k;
	while (k > 0) {
		int m, n, i, j;
		int sum = 0;
		
		// 矩阵的大小是 m x n
		cin >> m >> n;
		
		// matrix 是一个数组，它里面的每一个元素都是指针
		// 它的大小是 m，也就是一共有 m 个指针在里面～
		// 其中每一个指针都是矩阵的一行
		int ** matrix = new int* [m];
		
		// 那么既然说 matrix 里每一个指针都是矩阵的一行
		// 前面窝们也拿到了矩阵的大小，也就是一行有 n 个数字～
		// 那么这里每一个指针都需要 n 个 int 的大小来保存
		for (int i = 0; i < m; i++) {
			matrix[i] = new int [n];
		}
		
		// 接下来输入每一个数～
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		
		// 蓝后计算矩阵边缘的和
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (i == 0 || i == m-1 || j == 0 || j == n - 1) {
					sum += matrix[i][j];
				}
			}
		}

		cout << sum << endl;
		k--;
		
		// 每次完了之后要清理掉不用的内存～
		for (int i = 0; i < m; i++) {
			delete [] matrix[i];
		}
		delete [] matrix;
	}
	return 0;
}