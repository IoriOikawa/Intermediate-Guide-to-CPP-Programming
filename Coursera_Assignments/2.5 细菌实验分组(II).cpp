#include <iostream>
#include <memory.h>
#include <cstdlib>

using namespace std;

typedef struct pair_t {
	int diff;
	int id;
} pair_t, * Pair;

int comp(const void *a, const void *b) {
	return ((*(struct pair_t **)a)->diff - (*(struct pair_t **)b)->diff) > 0;
}

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		// (increment, id)
		/*
		
5
1 10 3456
2 10 5644
3 10 4566
4 20 234
5 20 232
		
		[(3446, 1), (5634, 2), (4556, 3), (214, 4), (212, 5)]
		[(5634, 2), (4556, 3), (3446, 1), (214, 4), (212, 5)]
		last_index_of_group_a = 2
		
		
		*/
		struct pair_t ** bacterial = (struct pair_t **)malloc(sizeof(struct pair_t) * n);
		
		memset(bacterial, 0, sizeof(struct pair_t) * n);
		
		for (int i = 0;i < n;i++) {
			bacterial[i] = new struct pair_t;
			int id, initial, end;
			cin >> id >> initial >> end;
			bacterial[i]->diff = end - initial;
			bacterial[i]->id = id;
		}
		qsort(bacterial, n, sizeof(struct pair_t), comp);
		
		int max_difference = -1;
		int last_index_of_group_a;
		for (int i = 0;i < n - 1;i++) {
			int diff = bacterial[i]->diff - bacterial[i + 1]->diff;
			if (max_difference < diff) {
				max_difference = diff;
				last_index_of_group_a = i;
			}
		}
		
		int count_of_group_a = last_index_of_group_a + 1;
		cout << count_of_group_a << '\n';
		
		for (int i = last_index_of_group_a;i >= 0;i--) {
			cout << bacterial[i]->id << '\n';
		}
		
		cout << n - count_of_group_a << '\n';
		
		for (int i = n - 1;i > last_index_of_group_a;i--) {
			cout << bacterial[i]->id << '\n';
		}
	}
}