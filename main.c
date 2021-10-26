#include	"libft.h"
#include	<stdlib.h>
#include	<stdio.h>
#include	<ctype.h>

void	ft_color_prompt(int col)
{
	switch (col)
	{
		case 0:
			printf("\033[1;31m");	// red
			break;
		case 1:
			printf("\033[0;32m");	// green
			break;
	}	
}

void	ft_int_int(int (*ft_ptr)(int), int (*ptr)(int))
{
	int	c;

	c = -100;
	while (++c < 600)
	{

		if (isalnum(c) == ft_isalnum(c))
			ft_color_prompt(1);
		else
		{	
			ft_color_prompt(0);
			printf("IN : %d,\tOUT : %d\tEXPECTED %d\n", c, (ft_ptr)(c), (ptr)(c));
		}
	}
	return ;	
}

void	ft_str_sizet(const char** list, size_t (*ft_ptr)(const char*), size_t (*ptr)(const char*))
{
	int	i;

	i = -1;
	while (i++ < 2)
	{
		if ((ft_ptr)(list[i]) == (ptr)(list[i]))
			ft_color_prompt(1);
		else
			ft_color_prompt(0);
		printf("IN : %s,\tOUT : %zu\tEXPECTED %zu\n", list[i], (ft_ptr)(list[i]), (ptr)(list[i]));
	}
	return ;	

}

void	ft_str_int(const char** list, int (*ft_ptr)(const char*), int (*ptr)(const char*))
{
	int	i;

	i = -1;
	while (i++ < 2)
	{
		if (atoi(list[i]) == ft_atoi(list[i]))
			ft_color_prompt(1);
		else 
			ft_color_prompt(0);

		printf("IN : %s,\tOUT : %d\tEXPECTED %d\n", list[i], (ft_ptr)(list[i]), (ptr)(list[i]));
	}
	return ;	
}


int	main(void)
{	
	const char *strings[] = {"one","two","three"};

	printf("\nisalnum\n");	
	ft_int_int(ft_isalnum, isalnum);
	
	printf("\natoi\n");	
	ft_str_int(strings, ft_atoi, atoi);
	
	printf("\nstrlen\n");	
	ft_str_sizet(strings, ft_strlen, strlen);
	
	return (0);
}
