#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int BUFFER_SIZE;

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*join_buffer(char const *s1, char const *s2);
int		check_nl_symbol(char *str);

#endif
