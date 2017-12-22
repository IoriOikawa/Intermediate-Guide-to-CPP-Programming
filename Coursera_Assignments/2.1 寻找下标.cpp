#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n = 0;
    while (cin >> n) {
        int i = 0;
        int flag = 0;
        while (n--) {
            int number;
            cin >> number;
            if (flag == 0 && number == i) {
                cout << i << '\n';
                flag = 1;
            }
            i++;
        }
        if (flag == 0) {
            cout << "N\n";
        }
    }
}
