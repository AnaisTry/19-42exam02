#include<unistd.h>
#include<stdarg.h>
#define HEX "0123456789abcdef"
int	putstr(const char *s);
int	putnbr(long long n, int base);
int	ft_print(const char	*s, va_list	args);

int	ft_printf(const	char *s, ...)
{

	va_list	args;
	int	len;
	
	va_start(args, s);
	len = ft_print(s, args);
	va_end(args);
	return(len);
}

int	ft_print(const char	*s, va_list	args)
{
		int		len = 0;
	
	while (*s)
	{
		if (*s != '%')
			len += write(1, s, 1);
		else
		{
			s++;
			//if (*s == 'c')
			//	len += write(1, va_arg(args, char), 1);
			if (*s == 's')
				len += putstr(va_arg (args, const char *));
			if (*s == 'd')
				len += putnbr((long long)va_arg (args, int), 10);
			if (*s == 'x')
				len += putnbr((long long)va_arg(args, unsigned int), 16);
		}
		s++;
	}
		
	return (len);
}

int	putstr(const char *s)
{
	int	len = 0;

	if (!s)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		while (*s)
		{
			len += write(1, s, 1);
			s++;
		}
	}
	return (len);
}


int	putnbr(long long n, int base)
{
	int	len = 0;

	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)
		len += putnbr(n/base, base);
	len += write(1, &HEX[n%base], 1);
	return(len);
}	
