#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

// 构造二维数组...
    
    
    int row, col, i, j, r = 0, c = 0;
    cin >> row >> col;
    
    // 矩阵嘛～当然一共就是 row * col 个 int 啦w
    int * A = new int[row * col];
    // 那么访问的时候怎么办呢～
    // 以 3 x 2 矩阵为例子吧
    // 它一共有 6 个元素
    //   - [0, 2) 为第 1 个行向量
    //   - [2, 4) 为第 2 个行向量
    //   - [4, 6) 为第 3 个行向量
    // 那么对应关系就是
    // A[0][0] -> A[0]
    // A[0][1] -> A[1]
    // A[1][0] -> A[2]
    // A[1][1] -> A[3]
    // A[2][0] -> A[4]
    // A[2][1] -> A[5]
    // 可以看到原本的大小为 row x col 的二维矩阵 A, ，在使用指针之后，
    // A[i][j] 就对应于了 A[i * col + j]
    // 为什么要 i * col 呢，因为每一行都有 col 个元素呀～
    // 跳过 i * col 个，不就是跳过了前面 i 行么w
    
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            cin >> A[i * col+j];
            
// 以第0行第0列递增为起点遍历col次...
    
    for (j = 0; j < col; j++){
        r = 0;
        c = j;      
        while (r < row && c >= 0)
            cout << A[r++ * col + c--] << endl;
    }
    
// 以第col-1列，col-1行递增为起点遍历row-1次...
    
    for (i = 1; i < row; i++){
        r = i;
        c = col - 1;        
        while (r < row && c >= 0)
            cout << A[r++ * col + c--] << endl;
    }
    
    return 0;
    
}

// 诶嘿嘿～其实米有太大区别吧www
