/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 20:52:27 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/02 21:02:38 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_help(char type)
{
	(void)type;
	ft_putendl("--> Usage");
	/*
	if (type == 0)
	{
		my_w("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n");
		my_w("Set each NAME to VALUE in the environment and run COMMAND.\n");
		my_w("\nMandatory arguments to long options are mandatory for ");
		my_w("short options too.\n");
		my_w("  -i, --ignore-environment  start with an empty environment\n");
		my_w("  -0, --null           end each output line with 0 byte rather ");
		my_w("than newline\n");
		my_w("  -u, --unset=NAME     remove variable from the environment\n");
		my_w("      --help     display this help and exit\n");
		my_w("      --version  output version information and exit\n");
		my_w("\nA mere - implies -i.  If no COMMAND, print the resulting ");
		my_w("environment.\n\nReport env bugs to bug-coreutils@gnu.org\nGNU ");
		my_w("coreutils home page: <http://www.gnu.org/software/coreutils/>\n");
		my_w("General help using GNU software: <http://www.gnu.org/gethelp/>\nF");
		my_w("or complete documentation, run: info coreutils 'env invocation'\n");
		return (1);
	}
	my_w("env (GNU coreutils) 8.21\nLicense GPLv3+: GNU GPL version 3 or later");
	my_w(" <http://gnu.org/licenses/gpl.html>.\nThis is free software: ");
	my_w("you are free to change and redistribute it.\n");
	my_w("There is NO WARRANTY, to the extent permitted by law.\n\n");
	my_w("Written by Richard Mlynarik and David MacKenzie.\n");
	*/
	return (1);
}

static char	ft_little_opt(char *opt, char *str)
{
	char	little[3];
	int		i;
	int		j;

	opt[ID_UN] = 0;
	little[ID_IGNORE] = 'i';
	little[ID_NULL] = '0';
	little[ID_UN] = 'u';
	i = 0;
	while (str[++i])
	{
		j = -1;
		while (++j < 3 && little[j] != str[i]);
		if (j == 3)
			return (ft_env_error(str, 1, i));
		else
			opt[j] = 1;
	}
	return (0);
}

static char	ft_big_opt(char *opt, char *str)
{
	int		i;
	char	**big;

	if ((big = malloc(sizeof(char *) * 5)) == NULL)
		ft_puterror("error: problem to malloc in my_env.c: l86\n");
	opt[ID_UN] = 0;
	big[ID_IGNORE] = "ignore-environment";
	big[ID_NULL] = "null";
	big[ID_UN] = "unset";
	big[ID_HELP] = "help";
	big[ID_VER] = "version";
	i = -1;
	while (++i < 5)
	{
		if ((i != 2 && ft_strcmp_shell(str, big[i], 0)) ||
				(i == 2 && ft_strcmp_shell(str, big[i], 1)))
		{
			opt[i] = 1;
			i = 5;
		}
	}
	ft_free_arg(big);
	if (i == 5)
		return (ft_env_error(str, 0, 0));
	return (0);
}

static char	ft_check_opt_env(t_env *env, char **var, char *opt,
		char ret)
{
	int		i;

	i = -1;
	while (ret == 0 && ++i >= 0 && var[i] != NULL)
	{
		if (var[i][0] == '-' && var[i][1] != '-' && var[i][1] != '\0')
		{
			ret = ft_little_opt(&opt[0], var[i]);
			if (opt[ID_UN] && ret == 0 && var[++i] != NULL)
				ft_remove_element(&env, var[i++]);
			else if (opt[ID_UN] && ret == 0 && var[i] == NULL)
				return (ft_env_error(NULL, 2, 0));
		}
		else if (var[i][0] == '-' && var[i][1] == '-' && var[i][2] != '\0')
		{
			ret = ft_big_opt(&opt[0], &var[i][2]);
			if (opt[ID_UN] && ret == 0 && UNSET(var[i][8]) && UNSET(var[i][9]))
				ft_remove_element(&env, &var[i][ft_strlen("--unset=")]);
			else if (opt[ID_UN] && ret == 0)
				return (ft_env_error(NULL, 3, 0));
		}
		if (opt[ID_HELP] || opt[ID_VER] || (var[i] != NULL && var[i][0] != '-'))
			return ((var[i][0] != '-') ? ++i: ft_help((opt[ID_HELP] == 1) ? 0 : 1));
	}
	return (ret);
}

char	ft_env_opt(t_env *env, char **var)
{
	char	opt[5];
	int	i;
	int	out;

	i = -1;
	while (++i < 5)
		opt[i] = 0;
	out = ft_check_opt_env(env, &var[1], &opt[0], 0);
	if (out == -1)
		return (-1);
	else if (out > 0)
		ft_exec((opt[ID_IGNORE] == 1) ? NULL : env, &var[out],
				ft_find_element(env, "PATH"));
	else if (out <= 0 && !opt[ID_IGNORE])
		ft_display_lst(env, opt[ID_NULL]);
	return (0);
}
