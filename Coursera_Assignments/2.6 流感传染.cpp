#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		char house[100][100] = {'#'};
		for (int row = 0; row < n; row++) {
			for (int column = 0; column < n; column++) {
				cin >> house[row][column];
			}
		}
		
		int m;
		cin >> m;
		
		char current_ill = '@';
		char empty_house = '#';
		char current_infant = '.';
		char ill_next_day = '*';
		
		int count = 0;
		
		for (int day = 1;day < m;day++) {
			for (int row = 0; row < n; row++) {
				for (int column = 0; column < n; column++) {
					char status = house[row][column];
					if (status == current_ill) {
						if (row > 0) {
							char up = house[row-1][column];
							if (up == current_infant) {
								house[row-1][column] = ill_next_day;
							}
						}
						if (row < n - 1) {
							char down = house[row+1][column];
							if (down == current_infant) {
								house[row+1][column] = ill_next_day;
							}
						}
						if (column > 0) {
							char left = house[row][column-1];
							if (left == current_infant) {
								house[row][column-1] = ill_next_day;
							}
						}
						if (column < n - 1) {
							char right = house[row][column+1];
							if (right == current_infant) {
								house[row][column+1] = ill_next_day;
							}
						}
					}
				}
			}
			
			for (int row = 0;row < n;row++) {
				for (int column = 0;column < n;column++) {
					if (house[row][column] == ill_next_day) {
						house[row][column] = current_ill;
					}
					
					if (day == m - 1 && house[row][column] == current_ill) {
						count++;
					}
				}
			}
		} 
		cout << count << '\n';
//		for (int row = 0; row < n; row++) {
//			for (int column = 0; column < n; column++) {
//				cout << house[row][column];
//			}
//			cout << '\n';
//		}

	}
}