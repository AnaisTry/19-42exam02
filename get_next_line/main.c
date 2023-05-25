# include "get_next_line.h"
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
