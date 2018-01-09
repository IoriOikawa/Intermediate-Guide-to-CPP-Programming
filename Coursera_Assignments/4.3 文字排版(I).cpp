#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
    char words[1000][40]; 
    
// 保存每一个单词
    
    int wordsLen[1000];
    
// 记录每一个单词的长度
    
    int n;
    
// 需要处理的单词总数
    
    cin >> n;
    cin.get();
    
// 输入单词数据，处理后得到每个单词的长度
    
    for (int i = 0; i < n;i++) {
        char temp;
        for (int j = 0; j < 40;j++) {
            cin.get(temp);              
            if (temp != ' ' && temp != '\n') {
                words[i][j] = temp;             
            } else {
                wordsLen[i] = j;
                break;
            }
        }
    }
    
// 先输出第一个单词
    
    int length = wordsLen[0];
    for (int j = 0; j < wordsLen[0]; j++)
        cout << words[0][j];
    for (int i = 1; i < n; i++) {
// 如果该单词，连同前面的一个空格加入后不换行，则输出空格和该单词
        if (length + 1 + wordsLen[i] <= 80) {
            length = length + 1 + wordsLen[i];
            cout << ' ';
            for (int j = 0; j < wordsLen[i]; j++)
                cout << words[i][j];
        } else {
// 如果该单词，连同前面的一个空格加入后换行，则输出回车和该单词，另外重置本行现有长度为单词长度
            cout << endl;
            length = wordsLen[i];
            for (int j = 0; j < wordsLen[i]; j++)
                cout << words[i][j];
        }
    }
    return 0;
}
