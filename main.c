#include "libft.h"

int main(int argc, char **argv)
{
	int res;

	if (argc < 3)
	{
		ft_putstr("Usage: ./samefiles {filename1} {filename2}\n");
	}
	else
	{
		res = ft_this_files_is_same(argv[1], argv[2]);
		if (!res)
			ft_putstr("No.\n");
		else if (res > 0)
			ft_putstr("Yes!\n");
		else
			ft_putstr("Error. Think better.\n");
	}
	return (0);
}
