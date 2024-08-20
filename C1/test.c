#include <stdio.h>

int mystery(int p, int q) {
	int r;
	if ((r = p % q) == 0) return q;
	else return mystery(q, r);

}

int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10}, i = 6 ;
	int *p = &a[0];
	printf("%d\n", *(p + i));
}
