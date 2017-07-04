#include "stdafx.h"

bool PaliCheck(int num) {
	const int D = 10;
	int rev_num(0), temp_num;
	temp_num = num;

	do {
		rev_num = rev_num*D + temp_num%D;
	} while (temp_num /= D);

	if (rev_num == num) return true;
	else return false;
}

int main()
{
	int min, max;
	int out;
	printf("Please enter min and max: ");
	scanf("%i %i", &min, &max);
	out = min;

	for (; out < max; out++)
		if (PaliCheck(out)) {
			printf("\n %i", out);
		}
	
	return 0;
}