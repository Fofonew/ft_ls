#include "ls.h"

void	show_content(char *dir_name, int R, t_option *option)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int				i;
	struct stat		buf;
	struct stat		bufc;
	char			*time;
	char			*tmp;
	int				t;
	int				t2;
	int 			stop;

	i = 0;

	tab = parsing(dir_name, option->optiont);
	if (tab != NULL)
	{
		if (option->optionr)
		{
			while(tab[i])
				i++;
			i -= 1;
		}
		if (option->optionl)
		{
			lstat(tab[i], &bufc);
			printf("total %lld\n", bufc.st_blocks);
		}
		while (tab[i])
		{
			if (option->optionr)
				if (i == 0)
					break;
			if (option->optionl)
			{
				t = 0;
				t2 = 0;
				stop = 0;
				lstat(tab[i], &buf);
				tmp = ctime(&buf.st_ctime);
				time = ft_strnew(12);
				while(tmp[t])
				{
					if (tmp[t] == ':')
					{
						stop++;
						if (stop == 2)
							break;
					}
					if (t < 4)
						t++;
					else
					{
						time[t2] = tmp[t];
						t2++;
						t++;
					}
				}
				if (option->optiona)
					printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
				else
					if (tab[i][0] != '.')
						printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
			}
			if (option->optiona)
				printf("%s\n", tab[i]);
			else if (R)
			{
				if (tab[i][0] != '.')
					printf("%s\n", tab[i]);
			}
			else if (tab[i][0] != '.')
				printf("%s\n", tab[i]);
			if (option->optionr)
				i--;
			else
				i++;
		}
	}
	if (R == 1)
		printf("\n");
}