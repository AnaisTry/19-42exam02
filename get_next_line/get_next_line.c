#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*gnl_strjoin(char *s1, char	*s2);
char	*ft_strchr(const  char *s, int c);
int		ft_strlen(char *s);
void	*ft_free(void *ptr);

char	*get_next_line(int fd)
{      
	
	char	buf[BUFFER_SIZE + 1];
	char 	*line = NULL;
	static	char *container;
	int		status = 1;
	char	*to_free;
	
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || fd >= INT_MAX)
		return (ft_free(container));
	
	//read and append
	*buf = '\0';
	while ((status > 0) && !ft_strchr(buf, '\n'))
	{
		status = read(fd, buf, BUFFER_SIZE);
		if (status < 0)
			return (ft_free(container));
		buf[status] = '\0';
		to_free = container;
		container = gnl_strjoin(container, buf);
		if (!container)
			return(NULL);
		free(to_free);
	}
	
	//extract line
	char	*end_of_line;
	int		line_len;
	line_len = 0;
	end_of_line = ft_strchr(container, '\n'); 
	if (end_of_line != NULL)
	{
		end_of_line++; //\n included
		line_len = end_of_line - container;
		line = malloc(sizeof(*line) * (line_len + 1));
		if (!line)	
			return(ft_free(container));
		for (int i = 0; i < line_len; i++)
			line[i] = container[i];
		line[line_len] = '\0';
	}
	else
	{
		if (!container[0])
			return (ft_free(container));
		line = gnl_strjoin(container, "");
		free(container);
		container = 0;
		return (line);
	}
	//keep leftover
	int start;
	int nb_chars_left;
	start = line_len;
	nb_chars_left = ft_strlen(container) - start;
	to_free = container;
	container = malloc(sizeof(*container) * (ft_strlen(end_of_line) + 1));
	for (int i = 0; i < nb_chars_left; i++)
		container[i] = end_of_line[i];
	container[nb_chars_left] = '\0';
	free(to_free);
	return (line);
}

char	*gnl_strjoin(char *s1, char	*s2)
{
	char	*joined;
	int		size = 0;
	int i = 0;
	
	if (!s1 && !s2)
		return(NULL);
	if (s1)
		size = ft_strlen(s1);
	if (s2)
		size  += ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (size + 1));
	if (!joined)
		return(NULL);
	while (s1 && *s1)
			joined[i++] = *s1++;
	while (s2 && *s2)
			joined[i++] = *s2++;
	joined[i]= '\0';

	return(joined);
}

char	*ft_strchr(const  char *s, int c)
{
	while (*s)
	{
		if (*s ==c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (0);
}

int	ft_strlen(char *s)
{
	int	len = 0;
	if (!s)
		return (0);

	while (s[len])
		len++;

	return (len);
}

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

# include <fcntl.h>
# include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int 	i = 0;

//	(void)argc;
//	(void)argv;
//	fd = 0;

	if (argc < 2)
	{
		printf("Usage: ./<program>.out fd\n");
		exit(1);
	}

	// check size of buffer
	// printf ("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	
	//open file
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n\n", fd);
/*	if (fd < 0)
	{
		printf("Could not open file.\n");
		exit(1);
	}
*/	
	// print each line until EOF
	while (1)
	{
		i++;
		printf("start of loop\n");
		line = get_next_line(fd);
		// line = get_next_line(fd);
		if (!line)
			break;
		printf("line %d : %s", i, line);
		printf("\nend of loop\n");
		free(line);
	}

	// close file
	if (close(fd) < 0)
	{
		printf("Could not close the file.\n");
		exit(1);
	}
	return (0);
}
