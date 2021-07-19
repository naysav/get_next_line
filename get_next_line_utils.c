#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	result;

	if (!s)
		return (0);
	result = 0;
	while (s[result])
		result++;
	return (result);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	if ((unsigned char *)dest > (unsigned char *)src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (counter < n)
		{
			((unsigned char *)dest)[counter] = *(unsigned char *)(src++);
			counter++;
		}
	}
	return (dest);
}

char	*join_buffer(char const *src, char const *dest)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	full_len;
	char	*result;

	if (!src && !dest)
		return (NULL);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	full_len = ft_strlen(src) + ft_strlen(dest) + 1;
	result = (char *)malloc(sizeof(char) * (full_len));
	if (result)
	{
		ft_memmove(result, src, src_len);
		ft_memmove(result + src_len, dest, dest_len);
		result[full_len - 1] = '\0';
		free((char *)src);
		return (result);
	}
	return (NULL);
}

int	check_nl_symbol(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
