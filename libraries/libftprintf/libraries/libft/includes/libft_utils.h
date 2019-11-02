/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:43:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <string.h>

# include "libft_macroses.h"

/*
**	Reading file line by line. (Get Next Line)
**	\param fd: File descriptor.
**	\param line: pointer to string where will saved each line from file.
**	\return:
**	[0 - End of File.
**	 1 - Successful read 1 line from file.
**	 -1 - Reading error.]
*/
int8_t	ft_gnl(int32_t const fd, char **line);

/*
**	Randomize unsigned decimal number.
**	\param limits: Max random number.
**	\return random: number from 0 to \ref limits.
*/
size_t	ft_rand(size_t const limit);

/*
**	Compare if one of \param n va_list arguments is equal to \param cmp.
**	\param cmp: Value to compare.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
*/
bool	ft_is_one_of_n(int64_t const cmp, size_t n, ...);

/*
**	Compare if one of \param n strings
**	 in va_list arguments is equal to \param cmp.
**	\param cmp: string to compare.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
**	note: length of strings DON'T use in
**	 compare via ft_strcmp() in this function.
*/
size_t	ft_is_one_of_str(char const *cmp, size_t const n, ...);

/*
**	Compare if one of \param n strings
**	 in va_list arguments is equal to \param cmp.
**	\param cmp: string to compare.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
**	note: length of strings IS use in
**	 compare via ft_strncmp() in this function.
*/
size_t	ft_is_one_of_strn(char const *cmp, size_t const n, ...);

/*
**	\return How many digits in \param n.
*/
size_t	ft_digits(int64_t n);

/*
**	\return How many digits in \param str.
**	If in string exist mantissa(data after .(dot) and actually .(dot))
**	 the function will return number of digits including this .(dot).
*/
size_t	ft_fdigits_str(char const *str);

/*
**	\return true is \param str contain only digits or false if not.
*/
bool	ft_isdigits_str(char const *const str);

/*
**	\return true is \param str contain only digits and valid float value
**	 or false if not.
*/
bool	ft_isfdigits_str(char const *const str);
/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool	ft_ishex_str(char *str);

/*
**	\return true if \param n symbols in string \param str
**		contains only hex digits or false if not.
*/
bool	ft_ishex_strn(char *str, size_t n);

/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool	ft_isalpha_str(char const *const str);

/*
**	\return How many blanks skips in string \param str.
*/
size_t	ft_skip_blanks(char const *const str);

/*
**	\return How many symbols to first blank symbol in string \param str.
*/
size_t	ft_skip_to_blank(char const *const str);

#endif
