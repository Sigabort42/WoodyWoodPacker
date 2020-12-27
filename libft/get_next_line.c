/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:38:55 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/07 23:42:09 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "libft.h"

int	ft_is_newline(t_varia *var, int fd, char **line)
{
	if (var->tab[fd] != 0 && !(var->rst = ft_strchr(var->tab[fd], '\n')))
		var->tab[fd] = ft_strjoin_free(ft_strdup(var->tab[fd]), 0);
	if (var->tab[fd] != 0 && (var->rst = ft_strchr(var->tab[fd], '\n')))
	{
		*line = ft_strjoin_free(ft_strcdup(var->tab[fd], '\n'), 0);
		var->tab[fd] = var->rst + 1;
		return (1);
	}
	else if (var->ret == 0 && var->tab[fd] != 0)
	{
		*line = ft_strjoin_free(ft_strcdup(var->tab[fd], '\n'), 0);
		if (ft_strlen(var->tab[fd]) != 0)
		{
			var->tab[fd] = 0;
			return (1);
		}
		var->tab[fd] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_varia	var;

	if (fd < 0 || fd > 4096 || read(fd, "", 0) < 0)
		return (-1);
	if (var.tab[fd] != 0 && (ft_is_newline(&var, fd, line)))
		return (1);
	var.buf = ft_strnew(BUFF_SIZE + 1);
	while ((var.ret = read(fd, var.buf, BUFF_SIZE)))
	{
		var.buf[var.ret] = '\0';
		if (!(var.rst = ft_strchr(var.buf, '\n')))
			var.tab[fd] = ft_strjoin_free(var.tab[fd], var.buf);
		if ((var.rst = ft_strchr(var.buf, '\n')))
		{
			*line = ft_strjoin_free(var.tab[fd], ft_strcdup(var.buf, '\n'));
			var.tab[fd] = var.rst + 1;
			return (1);
		}
		var.buf = ft_strnew(BUFF_SIZE + 1);
	}
	return (ft_is_newline(&var, fd, line)) ? (1) : (0);
}
