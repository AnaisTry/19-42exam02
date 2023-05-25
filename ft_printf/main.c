#include "ft_printf.h"
# include <stdio.h>
# include <limits.h>
//#define FORMAT "%s\n", "tr\nuc"
#define FORMAT "Hexadecimal for %d is %x\n", INT_MIN, INT_MIN

//#define FORMAT "%c\n", 't'
int	main(void)
{
	printf("  Yours: %d\n", ft_printf(FORMAT));
	printf("  Origi: %d\n", printf(FORMAT));
	return (0);
}
