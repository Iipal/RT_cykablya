/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:06:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:43:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <string.h>
# include "libft_macroses.h"

/*
**	Free memory for string and set \param as to NULL.
**	\param as pointer to string.
*/
void	ft_strdel(char **as);

/*
**	Reverse string \param str.
*/
void	ft_strrev(char *const str);

/*
**	Replace all \param search symbols in string \param str to \param replace.
*/
bool	ft_strrepchr(char *str,
			char const search,
			char const replace);

/*
**	Compare string \param s1 with \param s2.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int32_t	ft_strcmp(char const *s1, char const *s2);

/*
**	Compare string \param s1 with \param s2 by \param n symbols.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int32_t	ft_strncmp(char const *s1, char const *s2, size_t n);

/*
**	\return length of string \param str.
*/
size_t	ft_strlen(char const *const str);

/*
**	Appends the NUL-terminated string \param src to the end of \param dest.
**	It will append at most \param dstsize - ft_strlen(\param dst) - 1 bytes,
**	 NUL-terminating the result.
*/
size_t	ft_strlcat(char *const dest,
			char const *const src,
			size_t const dstsize);

/*
**	Copies up to \param dstsize - 1 symbols from the NUL-terminated
**	 string \param str to \param dest, NUL-terminating the result.
*/
size_t	ft_strlcpy(char *const dest,
			char const *const str,
			size_t const dstsize);

/*
**	\return converted string \str alphabet symbols to lower case.
*/
char	*ft_strlwr(char *str);

/*
**	\return converted string \str alphabet symbols to upper case.
*/
char	*ft_strupr(char *str);

/*
**	\return new allocated copy string \param src
**	 or NULL if something went wrong.
*/
char	*ft_strdup(char const *const src);

/*
**	\return new allocated copied \param n symbols from string \param src
**	 or NULL if something went wrong.
*/
char	*ft_strndup(char const *const s1, size_t const n);

/*
**	Copy string \param str to \param dest.
**	\return \param dest.
*/
char	*ft_strcpy(char *dest, char const *const str);

/*
**	Copy \param len of string \param src to string \param dest.
**	\return \param dest.
*/
char	*ft_strncpy(char *dest, char const *const src, size_t const len);

/*
**	Appends string \param src to \param dest.
**	\return \param dest.
*/
char	*ft_strcat(char *dest, char const *const src);

/*
**	Appends \param n symbols from string \param src to \param dest.
**	\return \param dest.
*/
char	*ft_strncat(char *dest, char const *const src, size_t const n);

/*
** \return a pointer to the first occurrence of the character \param c
**	 in the string \param s.
*/
char	*ft_strchr(char *str, char const c);

/*
**	\return a pointer to the last occurrence of the character \param c
**	 in the string \param s
*/
char	*ft_strrchr(char *s, char const c);

/*
** \return the first occurrence of the substring \param to_find
**  in the string \param str.
*/
char	*ft_strstr(char *str, char *to_find);

/*
** \return the first occurrence of the null-terminated string
**	 \param to_find in the string \param str,
**	 where not more than \param len characters are searched.
*/
char	*ft_strnstr(char *str, char const *const to_find, size_t len);

/*
**	\return allocate null-terminated string.
*/
char	*ft_strnew(size_t const size);

/*
**	\return allocate a “fresh” substring from the string \param s argument.
**	 The substring begins at index \param start and is of size \param len.
**	 If \param start and \param len aren’t refering to a valid substring,
**	 the behavior is undefined. If the allocation fails, returns NULL.
*/
char	*ft_strsub(char const *const s, size_t const start, size_t const len);

/*
**	\return allocate a “fresh” string ending with ’\0’,
**	 result of the concatenation of \param s1 and \param s2.
**	 If the allocation fails the function returns NULL.
*/
char	*ft_strjoin(char const *const s1, char const *const s2);

/*
**	\return allocate a copy of the string \param s without whitespaces
**	 at the beginning or at the end of the string.
**	 Will be considered as whitespaces the following characters ’ ’, ’\n’, ’\t’.
**	 If s has no whitespaces at the beginning or at the end,
**	 the function returns a copy of \param s.
**	 If the allocation fails the function returns NULL.
*/
char	*ft_strtrim(char const *const s);

/*
** \return allocate an array of “fresh” strings (all ending with ’\0’,
**	 including the array itself) obtained by spliting \param s
**	 using the character \param c as a delimiter.
**	 If the allocation fails the function returns NULL.
*/
char	**ft_strsplit(char *s, char const c);

/*
**	Convert string \param str to double type.
**	\return 0.0 if string \param str is invalid,
**	 else - number which contained in string
*/
double	ft_atof(char const *str);

/*
**	Convert string \param str to int32_t type.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
int32_t	ft_atoi(char const *str);

/*
**	Convert string \param str to int64_t number.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
int64_t	ft_atol(char const *str);

/*
**	Convert string \param str to int32_t number in \param base notation.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string converted in \param base notation.
*/
int32_t	ft_atoi_base(char const *str, int8_t const base);

/*
**	\return convert number \param n to string in \param base number system.
*/
char	*ft_ltoa_base(int64_t value, uint8_t base);

/*
**	\return convert number \param n to string.
*/
char	*ft_i128toa(__int128 n);

/*
**	\return convert number \param n to string.
*/
char	*ft_itoa(int32_t n);

#endif
