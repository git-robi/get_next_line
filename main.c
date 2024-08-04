#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("get_next_line: %s", line);
		if(!line) break;
		
	}
	free(line);
	return (0);
}
