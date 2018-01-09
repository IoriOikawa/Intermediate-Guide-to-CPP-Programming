#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])

{

// 构造二维数组...
	
	int A[100][100];
	int row, col, i, j, r = 0, c = 0;
	
	cin >> row >> col;
	
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> A[i][j];
			
// 以第0行第0列递增为起点遍历col次...
	
	for (j = 0; j < col; j++){
		r = 0;
		c = j;		
		while (r < row && c >= 0)
			cout << A[r++][c--] << endl;
	}
	
// 以第col-1列，col-1行递增为起点遍历row-1次...
	
	for (i = 1; i < row; i++){
		r = i;
		c = col - 1;		
		while (r < row && c >= 0)
			cout << A[r++][c--] << endl;
	}
	
	return 0;
	
}

// 所以这次又没有指针什么事儿了？