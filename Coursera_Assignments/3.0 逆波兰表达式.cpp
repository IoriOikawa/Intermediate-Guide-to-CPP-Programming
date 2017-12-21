//逆波兰表达式，
//提运算符于操作数前的表示法。
//四则运算实例，
//所有运算符及操作数均用空格隔开。
//eg: * / + 12 36 + 1 3 - 15 8
//out: 84


#include <iostream>

using namespace std;

double notation(){
	char str[10];
	cin >> str;
	switch (str[0])
	{
		case'*': return notation() * notation();
		case'/': return notation() / notation();
		case'+': return notation() + notation();
		case'-': return notation() - notation();
		default: return atof(str);
	}
}
int main(int argc, char *argv[]) {
	cout << notation();
	return 0;
}