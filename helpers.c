#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (num == 0)
		return (0);
	while ((i < num - 1) && (ptr1[i] != '\0' && ptr2[i] != '\0')
		&& (ptr1[i] == ptr2[i]))
		i++;
	return (ptr1[i] - ptr2[i]);
}

size_t	ft_strlen(const char *c)
{
	size_t	l;

	l = 0;
	while (c[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 != NULL && str1[j] != '\0')
		result[i++] = str1[j++];
	j = 0;
	while (str2 != NULL && str2[j] != '\0')
		result[i++] = str2[j++];
	result[i++] = '\0';
	return (result);
}

char *find_path(char **envp)
{	
	while(ft_strncmp("PATH=", *envp, 5))
        {
			envp++;
		}
	return (*envp + 5);
}