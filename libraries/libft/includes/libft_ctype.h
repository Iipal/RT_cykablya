/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:04:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 12:52:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII digit, else - false.
*/
bool	ft_isdigit(char const c);
# define F_ISDIGIT(c) ((c) >= 0x30 && (c) <= 0x39)

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol or is ASCII digit,
**	 else - false.
*/
bool	ft_isalnum(char const c);
# define F_ISALNUM(c) (F_ISDIGIT(c) || F_ISALPHA(c))

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower ASCII symbol, else - false.
*/
bool	ft_isascii(char const c);
# define F_ISASCII(c) ((c) <= 0x7F)

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII printable symbol, else - false.
*/
bool	ft_isprint(char const c);
# define F_ISPRINT(c) ((c) >= 0x20 && F_ISASCII(c))

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower case ASCII alphabet symbol, else - false.
*/
bool	ft_islower(char const c);
# define F_ISLOWER(c) ((c) >= 0x61 && (c) <= 0x7A)

/*
**	\param c - unsigned char.
**	\return true if \ref c is upper case ASCII alphabet symbol, else - false.
*/
bool	ft_isupper(char const c);
# define F_ISUPPER(c) ((c) >= 0x41 && (c) <= 0x5A)

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol, else - false.
*/
bool	ft_isalpha(char const c);
# define F_ISALPHA(c) (F_ISLOWER(c) || F_ISUPPER(c))

/*
**	\param c - unsigned char.
**	\return true if \ref c is '\t' '\n' '\v' '\f' '\r' or ' ', else - false.
*/
bool	ft_isblank(char const c);
# define F_ISBLANK(c) (((c) >= 0x9 && (c) <= 0xD) || (c) == 0x20)

/*
**	\param c - unsigned char.
**	\return If \ref c is lower case ASCII alphabet symbol
**	 return this symbol in upper case.
*/
char	ft_toupper(char const c);
# define F_TOUPPER(c) (F_ISLOWER(c) ? ((c) - ' ') : (c))

/*
**	\param c - unsigned char.
**	\return If \ref c is upper case ASCII alphabet symbol
**	 return this symbol in lower case.
*/
char	ft_tolower(char const c);
# define F_TOLOWER(c) (F_ISUPPER(c) ? ((c) + ' ') : (c))

#endif
