/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:22:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:34:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/api.h"
#include "libft/str.h"

static const char	g_months[12][3] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

static const char	g_days[7][3] =
{
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};

static const char	*g_num[60] =
{
	"00", "01", "02", "03", "04", "05", "06", "07", "08", "09",
	"10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
	"20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
	"30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
	"40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
	"50", "51", "52", "53", "54", "55", "56", "57", "58", "59"
};

inline char	*ft_ctime(const time_t *clock)
{
	char		*string;
	char		*year;
	struct tm	*tm;

	string = ft_strctor(25);
	tm = localtime(clock);
	ft_strncat(string, g_days[tm->tm_wday], 3);
	ft_strcat(string, " ");
	ft_strncat(string, g_months[tm->tm_mon], 3);
	ft_strcat(string, " ");
	ft_strcat(string, g_num[tm->tm_mday]);
	ft_strcat(string, " ");
	ft_strcat(string, g_num[tm->tm_hour]);
	ft_strcat(string, ":");
	ft_strcat(string, g_num[tm->tm_min]);
	ft_strcat(string, ":");
	ft_strcat(string, g_num[tm->tm_sec]);
	ft_strcat(string, " ");
	year = ft_itoa(tm->tm_year + 1900);
	ft_strcat(string, year);
	ft_strdtor(&year);
	string[24] = '\n';
	GIMME(string);
}
