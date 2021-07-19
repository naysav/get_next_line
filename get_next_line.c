#include "get_next_line.h"

char	*refresh(char *st_str)
{
	char	*result;
	size_t	skip_len;
	size_t	result_len;

	skip_len = 0;
	result_len = 0;
	if (!st_str)
		return (NULL);
	while (st_str[skip_len] && st_str[skip_len] != '\n')
		skip_len++;
	if (!st_str[skip_len])
	{
		free(st_str);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(st_str) - skip_len + 1));
	if (!result)
		return (NULL);
	skip_len++;
	while (st_str[skip_len])
		result[result_len++] = st_str[skip_len++];
	result[result_len] = '\0';
	free(st_str);
	return (result);
}

char	*create_line(char *string)
{
	char	*result;
	int		length;
	int		counter;

	length = 0;
	while (string[length] && string[length] != '\n')
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	counter = 0;
	while (string[counter] && string[counter] != '\n')
	{
		result[counter] = string[counter];
		counter++;
	}
	result[counter] = '\0';
	return (result);
}

int	free_and_return(char *buffer, int status)
{
	free(buffer);
	if (status == -1)
		return (-1);
	if (status == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*static_variable;
	int			status;

	status = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while ((!check_nl_symbol(static_variable)) && status != 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
			return (free_and_return(buffer, status));
		buffer[status] = '\0';
		static_variable = join_buffer(static_variable, buffer);
	}
	*line = create_line(static_variable);
	static_variable = refresh(static_variable);
	return (free_and_return(buffer, status));
}
