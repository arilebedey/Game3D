#include "../../include/error.h"
#include "../../include/rgb.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_numeric(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_rgb_value(int *dest, char *line)
{
	char	**split;
	t_rgb	rgb;
	char	*tmp;

	if (!line)
		return (perr("Error\nMissing RGB values"), 1);
	split = ft_split(line, ',');
	if (!split)
		return (perr("Error\nRGB split malloc"), 1);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_tab(split);
		return (perr("Error\nInvalid number of RGB args or extra comma"), 1);
	}
	tmp = ft_strtrim(split[2], "\n");
	if (!tmp)
		return (free_tab(split), perr("Error\nft_strtrim malloc"), 1);
	free(split[2]);
	split[2] = tmp;
	if (!is_numeric(split[0]) || !is_numeric(split[1]) || !is_numeric(split[2]))
		return (free_tab(split), perr("Error\nRGB values must be numeric only"),
			1);
	rgb.red = ft_atoi(split[0]);
	rgb.green = ft_atoi(split[1]);
	rgb.blue = ft_atoi(split[2]);
	free_tab(split);
	if (rgb.red < 0 || rgb.red > 255 || rgb.green < 0 || rgb.green > 255
		|| rgb.blue < 0 || rgb.blue > 255)
		return (perr("Error\nRGB value out of range"), 1);
	*dest = encode_rgb(rgb);
	return (0);
}
