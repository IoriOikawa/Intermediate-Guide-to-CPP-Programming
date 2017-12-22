#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    int i;
    double employee[3] = {0};
    double invoice[3] = {0};
    
    for (i = 0;i < 3;i++) {
        int id;
        int amount;
        cin >> id >> amount;
        for (int t = 0; t < amount; t++) {
            char type;
            double payment;
            cin >> type >> payment;
            
            invoice[type - 'A'] += payment;
            employee[id - 1] += payment;
        }
    }
    
    cout.precision(2);
    cout << std::fixed;
    
    for (int i = 0;i < 3;i++) {
        cout << i + 1 << ' ' << employee[i] << '\n';
    }
    
    for (int i = 0;i < 3;i++) {
        cout << (char)(i + 'A') << ' ' << invoice[i] << '\n';
    }
}
