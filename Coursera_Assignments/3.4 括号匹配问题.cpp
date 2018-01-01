#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main() {
	int i;
	char str[101], Mark[101];
	while(scanf("%s", str) != EOF) {
		stack<char> S;
		for (i = 0; i < strlen(str);i++) {
			if (str[i] == '(') {
				S.push(i);
				Mark[i] = ' ';
			}
			else if (str[i] == ')') {
				if (S.empty()) {
					Mark[i] = '?';
				}
				else {
					Mark[i] = ' ';
					S.pop();
				}
			}
			else {
				Mark[i] = ' ';
			}
		}
		while (!S.empty()) {
			Mark[S.top()] = '$';
			S.pop();
		}
		Mark[i] = '\0';
		puts(str);
		puts(Mark);
	}
	return 0;
}