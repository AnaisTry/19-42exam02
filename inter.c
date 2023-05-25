#include <unistd.h>

char    *ft_strchr(char *s, int c);
char    *char_already_passed(char *s,char to_find, int stop);

int     main(int ac, char** av)
{
	//If the number of arguments is not 2, the program displays \n
        if (ac != 3)
	{
	    write (1, "\n", 1);
            return (1);
	}

        char    *s1 = av[1];
        char    *s2 = av[2];

        //iterate on s1 and if the char is among s2  and was not already printed, print it
        int i = 0;
        while (s1[i])
        {
                if (ft_strchr(s2, s1[i]))
                {
                        //check if already printed
                        if (!char_already_passed(s1, s1[i], i))
                                write(1, &s1[i], 1);
                }
                i++;
        }
        write(1, "\n", 1);
        return (0);
}


char    *char_already_passed(char *already_passed, char to_find, int stop)
{
        int i = 0;

        while (i < stop)
        {
                if (to_find == already_passed[i])
                        return (already_passed);
                ++i;
        }
        return (0);
}

char    *ft_strchr(char *s, int c)
{
        while (*s)
        {
                if (*s == c)
                        return (s);
                s++;
        }
        if (*s == c)
                return (s);
        return (0);
}
