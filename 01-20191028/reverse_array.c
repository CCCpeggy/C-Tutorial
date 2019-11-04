#include <stdio.h>
void Reverse2D(int table[2][3], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", *(*(table + i) + j));
		}
	}
}
int main(){
	int m = 2, n = 3;
	int array[][3]={{1, 2, 3}, {4, 5, 6}};
	Reverse2D(array, n, m);
}
