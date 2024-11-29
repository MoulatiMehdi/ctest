/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:40 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/14 12:11:48 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <string.h>

char	name[100];
extern char g_desc[];

const char *ft_strsig(int sig) {
    switch (sig) {
        case SIGINT:   return "SIGINT";
        case SIGTERM:  return "SIGTERM";
        case SIGSEGV:  return "SIGSEGV";
        case SIGFPE:   return "SIGFPE";
        case SIGILL:   return "SIGILL";
        case SIGABRT:  return "SIGABRT";
        case SIGQUIT:  return "SIGQUIT";
        case SIGKILL:  return "SIGKILL";
        case SIGALRM:  return "TIMEOUT";
        case 0 : return "NORMAL";
        default:       return "UNKOWN";
    }
}

char	*str_sig(int status)
{
	sprintf(name, "[%s]",ft_strsig(status));
	return (strdup(name));
}

int	test_signal(t_func buildin, t_func custom, void *args)
{
	int	exp;
	int	res;

	exp = run_test(buildin, args);
	res = run_test(custom, args);
	if (exp != res)
	{
		msg_fail(g_desc, str_sig(exp), str_sig(res));
		return (0);
	}
	return (1);
}
