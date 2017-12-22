#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory.h>
using namespace std;

typedef struct pair_t {
    // rate 代表繁殖率
    double rate;
    
    // id 是该培养皿的编号
    int id;
} pair_t;

// 用于比较两个 (struct pair_t *) 的大小关系
// 返回值等于0 - 相等
// 返回值小于0 - a 应该在 b 前
// 返回值大于0 - a 应该在 b 后
int comp(const void * a, const void * b) {
    // qsort 比较两个 (struct pair_t *) 的大小关系
    // 但是 qsort 传入的是这两个 (struct pair_t *) 的地址
    // 也就是 (struct pair_t **)
    // 所以 a, b 的实际类型是 (struct pair_t **)
    // 所以先要把传来的参数做一次类型转换
    struct pair_t ** atmp = (struct pair_t **)a;
    struct pair_t ** btmp = (struct pair_t **)b;
    
    // 接下来，因为 atmp, btmp 是指向 (struct pair_t *) 的指针
    // 所以窝们用「*」deference 一次
    // 得到原始的 (struct pair_t *)
    struct pair_t * aoriginal = *atmp;
    struct pair_t * boriginal = *btmp;
    
    // 然后再用「->」操作符获取它们的 rate 的大小并比较
    return boriginal->rate - aoriginal->rate;
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n) {
        /**
         - 输入
         5
         1 10 3456
         2 10 5644
         3 10 4566
         4 20 234
         5 20 232
         
         - 计算繁殖率
           繁殖率 = 最终数量 / 初始数量
           做除法而不是做减法
         
         - 保存到 bacterial 数组中
           pair_t 的含义是 (rate, id)
           [(345.6, 1), (564.4, 2), (456.6, 3), (11.7, 4), (11.6, 5)]
         
         - 按照繁殖率降序排序
           [(564.4, 2), (456.6, 3), (345.6, 1), (11.7, 4), (11.6, 5)]
         
         - 找出A, B 的分隔
           即繁殖率差异最大的地方
           [(564.4, 2), (456.6, 3), (345.6, 1) || (11.7, 4), (11.6, 5)]
                                               ^^
         - 输出 A 组的数量
           再按繁殖率升序输出 A 组的编号
         
         - 输出 B 组的数量
           再按繁殖率升序输出 B 组的编号
         */
        
        // 申请 n 个 大小为 sizeof(struct pair_t *) 的内存空间
        // 即 bacterial 是一个 指向 (struct pair_t *) 的数组
        // 一共可以存放 n 个 (struct pair_t *) 的地址
        struct pair_t ** bacterial = (struct pair_t **)malloc(sizeof(struct pair_t *) * n);
        
        // 将它们都初始化为 NULL
        memset(bacterial, 0, sizeof(struct pair_t *) * n);
        
        for (int i = 0;i < n;i++) {
            // new 出每一个具体的 (struct pair_t)
            // 并且将这个具体的 (struct pair_t) 的内存地址放入对应的 bacterial 数组中
            bacterial[i] = new struct pair_t;
            
            // 细菌组 初始数量 最终数量
            int id, initial, end;
            cin >> id >> initial >> end;
            
            // 计算繁殖率
            // 繁殖率 = 最终数量 / 初始数量
            // 做除法而不是做减法
            bacterial[i]->rate = (double)end / initial;
            bacterial[i]->id = id;
        }
        
        // 按照繁殖率降序排序
        qsort(bacterial, n, sizeof(struct pair_t *), comp);
        
        // 找出 A, B 的分隔
        // 即繁殖率差异最大的地方
        double max_difference = -1;
        int last_index_of_group_a = 0;
        for (int i = 0;i < n - 1;i++) {
            double diff = bacterial[i]->rate - bacterial[i + 1]->rate;
            if (max_difference < diff) {
                max_difference = diff;
                last_index_of_group_a = i;
            }
        }
        
        // 实际上不用考虑全是 A 组的情况
        // 因为实际上不存在这样的例子
        // 但是留着也没问题
        
        // 输出 A 组的数量
        int count_of_group_a = last_index_of_group_a + 1;
        cout << count_of_group_a << '\n';
        // 按繁殖率升序输出 A 组的编号
        for (int i = last_index_of_group_a;i >= 0;i--) {
            cout << bacterial[i]->id << '\n';
        }
        
        // 输出 B 组的数量
        cout << n - count_of_group_a << '\n';
        // 按繁殖率升序输出 B 组的编号
        for (int i = n - 1;i > last_index_of_group_a;i--) {
            cout << bacterial[i]->id << '\n';
        }
    }
}
