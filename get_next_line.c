#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 42

char * get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char * return_line;
	char * saver;
	char * saver_2;
	unsigned int index;
	unsigned int index_2;
	int result;

	index = 0;
	return_line = NULL;
	if (buffer[0] == '\0')
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1 || result == 0)
			return (NULL);
	}
	
	while (1)
	{
		if (buffer[index] == '\n')
			break ;
		if (buffer[index] == '\0')
		{
			if (return_line == NULL)
				return_line = ft_substr(buffer, 0, index);
			else
			{
				saver = return_line;
				return_line = ft_strjoin(return_line, buffer);
				free (saver);
			}
			result = read (fd, buffer, BUFFER_SIZE);
			if (result == -1)
				return (NULL);
			if (result == 0)
				break ;
			index = 0;
			continue ;
		}
		index++;
	}
	saver = return_line;
	saver_2 = ft_substr(buffer, 0, index + 1);
	if (return_line == NULL)
	{
		return_line = ft_substr(buffer, 0, index + 1);
		free(saver);	
	}
	else if (result != 0)
	{
		return_line = ft_strjoin(return_line, saver_2);
		free(saver);
	}
	
	free(saver_2);
	index++;
	index_2 = 0;
	while (buffer[index_2] != '\0')
	{
		if (buffer[index] != '\0')
			buffer[index_2] = buffer[index];
		else
			buffer[index_2] = '\0';
		index++;
		index_2++;
	}
	return (return_line);
}

int main()
{
	int fd = open ("text", O_RDONLY);
	char * return_line = get_next_line(fd);
	printf("%s", return_line);
	get_next_line(fd);
	printf("%s", return_line);
	get_next_line(fd);
	printf("%s", return_line);
}