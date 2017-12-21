#include <iostream>
#include <iomanip>

using namespace std;

void kakuTani(int a)
{
	if (a == 1) //得到1之后输出End,
	{
		printf("End");
		return; //并跳出递归函数.
	}
	else if (a % 2 == 0) //否则进入递归过程, 理论上将直到结果为1为止.
	{
		printf("%d/2=%d\n", a, a / 2);
		return kakuTani(a / 2);
	}
	else if (a % 2 != 0)
	{
		printf("%d*3+1=%d\n", a, 3 * a + 1);
		return kakuTani(3 * a + 1);
	}
}

int main(int argc, char *argv[]) {
	
	int a = 0;
	cin >> a;
	kakuTani(a);
	return 0;
}