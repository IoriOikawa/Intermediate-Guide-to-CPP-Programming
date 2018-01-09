#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void match_bracket(int i, char *str, int * stack, int &stack_size, char * mark) {
    if (i > strlen(str)) {
        return;
    }
    if (str[i] == '(') {
        stack[stack_size] = i;
        stack_size++;
        mark[i] = ' ';
    } else if (str[i] == ')') {
        if (stack_size == 0) {
            mark[i] = '?';
        } else {
            mark[i] = ' ';
            stack_size--;
        }
    } else {
        mark[i] = ' ';
    }
    match_bracket(i+1, str, stack, stack_size, mark);
}

int main() {
    char str[101], Mark[101];
    int stack[101];
    while(scanf("%s", str) != EOF) {
        int stack_size = 0;
        match_bracket(0, str, stack, stack_size, Mark);
        while (stack_size != 0) {
            Mark[stack[stack_size]] = '$';
            stack_size--;
        }
        Mark[strlen(str)] = '\0';
        puts(str);
        puts(Mark);
    }
    return 0;
}
