#include <iostream>
#include <iomanip>

using namespace std;

void reverseString(char s[], int l, int len){
	
    char tmpStr[1001];
	int tmpLen = 0, i = l;
	bool isEmpty = false;
	for( ; i < len; i++) {
		if(s[i] != ' '){
			tmpStr[tmpLen++] = s[i];
		}
		else {
			while(tmpLen){
				cout << tmpStr[--tmpLen];
			}
			cout << ' ';
			isEmpty = true;
			reverseString(s, i + 1, len);
			break;
			}
	}
	if(!isEmpty) {
		while(tmpLen) {
			cout << tmpStr[--tmpLen];
		}
	}
	return;
}

int main(int argc, char *argv[]) {
	int count = 100;
	char s[1001];
	while(count--) {
		cin.getline(s, 1000);
		reverseString(s, 0, strlen(s));
		cout << "\n";
	}
}
