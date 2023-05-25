#include <unistd.h>

char	*char_already_printed(char	*already_printed, char to_find, int	stop);
char	*ft_strchr(const  char *s, int c); 

int	main(int ac, char **av)
{
	//If the number of arguments is not 2, the program displays \n
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	
	char *s1 = av[1];
	char *s2 = av[2];
	int i = 0;
	
	// in the order of the command line
	while (s1[i])
	{
		// if the char was not already printed, print
		if (!(char_already_printed(s1, s1[i], i)))
			write(1, &s1[i], 1);	
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!(char_already_printed(s2, s2[i], i)) && !(ft_strchr(s1, s2[i])))
			write(1, &s2[i], 1);
		i++;
	}
	//followed by a \n
	write(1, "\n", 1);
	return (0);
}


char	*char_already_printed(char	*already_printed, char to_find, int	stop)
{
	int i = 0;
	
	while (i < stop)
	{
		if (to_find == already_printed[i])
			return (already_printed);
		i++;
	}
	return (0); 
}


char	*ft_strchr(const  char *s, int c)
{
	while (*s)
	{
		if (*s ==c)
			return ((char *)s);  
		s++;
	} 
	return (0); 
} 
