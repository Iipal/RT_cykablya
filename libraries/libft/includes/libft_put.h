/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:02:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:42:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_macroses.h"

/*
**	Put \param c char to stdout.
*/
void	ft_putchar(char const c);
# define F_PUTCHAR(c) write(1, &c, 1)

/*
**	Put \param c char to stdout by \param n times.
*/
void	ft_putnchar(char const c, size_t n);

/*
**	Put \param s string to stdout.
*/
void	ft_putstr(char const *const s);

/*
**	Put \param s string to stdout followed by newline.
*/
void	ft_putendl(char const *const s);

/*
**	Put \param n number to stdout.
*/
void	ft_putnbr(int64_t n);

/*
**	Put \param c char to specified \param fd output.
*/
void	ft_putchar_fd(char const c, int32_t const fd);
# define F_PUTCHAR_FD(c, fd) write(fd, &c, 1);

/*
**	Put \param s string to specified \param fd output.
*/
void	ft_putstr_fd(char const *const s, int32_t const fd);

/*
**	Put \param s string to specified \param fd output followed by newline.
*/
void	ft_putendl_fd(char const *s, int32_t const fd);

/*
**	Put number \param n
*/
void	ft_putnbr_fd(int32_t n, int32_t const fd);

/*
**	Print all strings from \param file to stdout or return false.
*/
bool	ft_putfile(char const *const file);

#endif
