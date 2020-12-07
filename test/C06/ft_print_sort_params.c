
int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
void	ct(char *a, char *b)
{
	char	*temp;

	temp = a;
	a = b;
	b = temp;
}
void	quick_sort(char **args, int size)
{
	int	j;
	int	i;
	int p;

	if (size < 2)
		return ;
	p = (size / 2);
	j = size;
	i = -1;
	while (i < j)
		{
			while (i++ && ft_strcmp(args[f],args[i]) < 0);
			while (j-- && ft_strcmp(args[f],args[j]) > 0);
			ct(args[i],args[j]);
		}
	quick_sort(args, i);
	quick_sort(args + i + 1, size - i - 1);
}

int	main(int size, char **args)
{
	quick_sort(args + 1,size - 1);
		while(size && *(++args))
			while(**(args))
				write(1, *((*args)++), 1);
	return (0);
}
