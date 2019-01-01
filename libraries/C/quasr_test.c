#include "libft/includes/libft.h"
#include <stdio.h>

/*

Get the correct function
Parse the parameters
Cast the parameters
Execute the function
	Returns a pointer -> send an id
	Returns a value -> send the value
*/

int main(int ac, char**av)
{
	char *text;
	ft_printf("What function ? ");
	get_next_line(0, &text);
	if (!ft_strcmp("ft_strlen", text)) {
		get_next_line(0, &text);
	}
}
