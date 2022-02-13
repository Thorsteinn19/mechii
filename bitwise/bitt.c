
#include <stdio.h>

int main()
{
	unsigned char c=0x00;
	printf("%d",c);
	c |= 1<<5;
	printf("%d",c);
	c &= ~1<<5;
	printf("%d",c);
	c ^= 1<<5;
	printf("%d",c);
return 0;
}
