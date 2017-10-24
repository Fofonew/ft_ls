#include "ls.h"

char	**sort_param_time(char **tab)
{
	int		i;
	char	*tmp;
	int		power;
	struct stat buf;
	struct stat buf2;

	power = 1;
	while (power)
	{
		power = 0;
		i = 1;
		while (tab[i])
		{

			if (tab[i + 1] != '\0')
			{

				stat(tab[i], &buf);
				stat(tab[i + 1], &buf2);
				if ((buf.st_mtime) < (buf2.st_mtime))
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					power = 1;
				}
			}
			i++;
		}
	}
	return (tab);
}

char	**sort_param(char **tab)
{
	int		i;
	char	*tmp;
	int		power;

	power = 1;
	while (power)
	{
		power = 0;
		i = 1;
		while (tab[i])
		{
			if (tab[i + 1] != '\0')
				if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					power = 1;
				}
			i++;
		}
	}
	return (tab);
}

char	**parsing(char *dir_name, int t)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			*str = NULL;
	char			**tab;
	int				a = 0;
	int				b = 0;
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		perror(dir_name);
		b = 1;
	}
	if (b != 1)
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if (a == 0)
				str = ft_strdup(dirent->d_name);
			if (a == 1)
			{
				str = ft_strjoin(str, "%");
				str = ft_strjoin(str, dirent->d_name);
			}
			a = 1;
		}
		tab = ft_strsplit(str, '%');
		if (t)
			sort_param_time(tab);
		else
			sort_param(tab);
		closedir(dir);
		return(tab);
	}
	return (NULL);
}