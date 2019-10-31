#include "strtof.h"

#pragma GCC diagnostic ignored "-Wpadded"

#ifndef true
# define true (1)
#endif
#ifndef false
# define false (0)
#endif

enum	e_table_values
{
	__ten_to_the,
	__ten_to_the_minus
};

__attribute__((__const__,__gnu_inline__,__always_inline__,__flatten__))
static inline float	table_values(int table, int val)
{
	return ((const float*[]){
		(const float[]){
			01e0f, 01e1f, 01e2f, 01e3f, 01e4f, 01e5f, 01e6f, 01e7f, 01e8f,
			01e9f, 1e10f, 1e11f, 1e12f, 1e13f, 1e14f, 1e15f, 1e16f, 1e17f,
			1e18f, 1e19f, 1e20f, 1e21f, 1e22f, 1e23f, 1e24f, 1e25f, 1e26f,
			1e27f, 1e28f, 1e29f, 1e30f, 1e31f, 1e32f, 1e33f, 1e34f, 1e35f,
			1e36f, 1e37f, 1e38f },
		(const float[]){
			01e+0f, 01e-1f, 01e-2f, 01e-3f, 01e-4f, 01e-5f, 01e-6f, 01e-7f,
			01e-8f, 01e-9f, 1e-10f, 1e-11f, 1e-12f, 1e-13f, 1e-14f, 1e-15f,
			1e-16f, 1e-17f, 1e-18f, 1e-19f, 1e-20f, 1e-21f, 1e-22f, 1e-23f,
			1e-24f, 1e-25f, 1e-26f, 1e-27f, 1e-28f, 1e-29f, 1e-30f, 1e-31f,
			1e-32f, 1e-33f, 1e-34f, 1e-35f, 1e-36f, 1e-37f }
	}[table][val]);
}


typedef union u_uint32	t_uint32;
typedef __UINT32_TYPE__ __attribute__((__aligned__(1),__may_alias__))	t_a_uint32;

union					u_uint32
{
	__UINT32_TYPE__	__attribute__((__aligned__(1),__may_alias__))	aliased;
	__UINT32_TYPE__													aligned;
};

static _Bool __attribute__((__pure__))
strtof_small_lencheck(char *restrict s)
{
	__SIZE_TYPE__	limit;

	limit = ~0UL;
	while (s[++limit])
		if (limit == 3UL)
			return (true);
	return (limit >= 3UL);
}

static _Bool __attribute__((__pure__))
is_inf_keyword(char s[static 4])
{
	const t_uint32 s_inf = { *((t_a_uint32 *restrict)s) & 0xFFFFFFU };
	const __UINT32_TYPE__ inf_table[] = { *((const t_a_uint32*)"inf"),
											*((const t_a_uint32*)"Inf"),
											*((const t_a_uint32*)"iNf"),
											*((const t_a_uint32*)"inF"),
											*((const t_a_uint32*)"INf"),
											*((const t_a_uint32*)"iNF"),
											*((const t_a_uint32*)"InF"),
											*((const t_a_uint32*)"INF") };

	return ((s_inf.aligned == inf_table[0x0])
		|| (s_inf.aligned == inf_table[0x7])
		|| (s_inf.aligned == inf_table[0x1])
		|| (s_inf.aligned == inf_table[0x2])
		|| (s_inf.aligned == inf_table[0x3])
		|| (s_inf.aligned == inf_table[0x4])
		|| (s_inf.aligned == inf_table[0x5])
		|| (s_inf.aligned == inf_table[0x6]));
}

#ifndef HUGE_10_POW
# define HUGE_10_POW (38)
#endif

static _Bool __attribute__((__pure__))
is_strof_value_out_of_range(int exponent, int sig_digs)
{
	return (((exponent + (sig_digs - 1)) > HUGE_10_POW)
	|| ((exponent + (sig_digs - 1)) < -HUGE_10_POW));
}

#undef HUGE_10_POW


static inline float __attribute__((__gnu_inline__,__always_inline__))
strof_return_result(float result,
					char *restrict s,
					char **restrict endptr,
					_Bool is_negative,
					_Bool is_errno)
{
	if (is_errno)
		errno = ERANGE;
	if (endptr)
		*endptr = (char*)s;
	return (is_negative ? -result : result);
}


static float __attribute__((,))
strof_stop_conversion(char *restrict s, char **restrict endptr,
	int value, int sig_digs, int exponent, _Bool is_negative)
{
	float	result;

	if (value == 0)
		return (strof_return_result(0.0f, s, endptr, is_negative, false));
	else if (is_strof_value_out_of_range(exponent, sig_digs))
		return (strof_return_result((exponent + (sig_digs - 1) > 38)
		? __builtin_huge_valf() : 0.0f, s, endptr, is_negative, true));
	else if (exponent >= 0)
	{
		result = (float)value * table_values(__ten_to_the, exponent);
		if (__builtin_isinf(result))
			return (strof_return_result(__builtin_huge_valf(), s, endptr, is_negative, true));
		return (strof_return_result(result, s, endptr, is_negative, false));
	}
	else if (exponent < -37)
	{
		result = (float)value * table_values(__ten_to_the_minus, sig_digs)
				* table_values(__ten_to_the_minus, -(exponent + sig_digs));
		return (strof_return_result(result, s, endptr, is_negative,
					(int)(result - 0.0f) || (int)(result + 0.0f)));
	}
	else
	{
		result = (float)value * table_values(__ten_to_the_minus, -exponent);
		return (strof_return_result(result, s, endptr, is_negative,
					((int)(result - 0.0f) || (int)(result + 0.0f))));
	}
}

static inline float __attribute__((__gnu_inline__,__always_inline__))
_strtof(char *restrict s, char **restrict endptr)
{
	int		value;
	int		sig_digs;
	int		exponent;
	int		exp_value;

	_Bool	is_dec_point;
	_Bool	is_negative;
	_Bool	is_exp_negative;

	value = 0;
	sig_digs = 0;
	exponent = 0;
	is_negative = false;

	while (*s != 0 && *s == ' ')
		s++;
	if (*s == 0)
		return 0.0f;
	s += ((*s == '+') || (is_negative |= (*s == '-')));

	if (strtof_small_lencheck(s) && is_inf_keyword(s))
		return strof_return_result(__builtin_inff(), s + 3, endptr, is_negative, false);
	if (!((*s >= '0' && *s <= '9') || (*s == '.')))
		return strof_return_result(0.0f, s, endptr, is_negative, true);

	is_dec_point = false;
	while ((*s >= '0' && *s <= '9') || (*s == '.'))
		if ((*s == '.') && is_dec_point)
			return (strof_stop_conversion(s, endptr, value, sig_digs, exponent, is_negative));
		else if ((*s == '.') && !is_dec_point && s++)
			is_dec_point = true;
		else if (sig_digs < 8)
		{
			sig_digs += !!(value = (value * 10) + (*s++ - '0'));
			exponent -= is_dec_point;
		}
		else if (!is_dec_point && s++)
			exponent++;
		else
			s++;

	if (*s == 'e' || *s == 'E')
	{
		exp_value = 0;
		is_exp_negative = false;
		if (++s && ((*s == '+') || (is_exp_negative = (*s == '-')))
		&& (++s && !(*s >= '0' && *s <= '9') && (s -= 2)))
			return (strof_stop_conversion(s, endptr, value, sig_digs, exponent, is_negative));
		else if (s && !(*s >= '0' && *s <= '9') && (s -= 1))
			return (strof_stop_conversion(s, endptr, value, sig_digs, exponent, is_negative));
		while (s && (*s >= '0' && *s <= '9'))
			if (exp_value < 100)
				exp_value = (exp_value * 10) + (*(s++) - '0');
			else
				s++;
		exponent += (is_exp_negative) ? -exp_value : exp_value;
	}

	return (strof_stop_conversion(s, endptr, value, sig_digs, exponent, is_negative));
}




















__attribute__((__optimize__("O0"),__flatten__))
float	o_strtof(char *restrict s, char **restrict endptr)
{
	return (_strtof(s, endptr));
}

__attribute__((__optimize__("Ofast"),__flatten__))
float	O_strtof(char *restrict s, char **restrict endptr)
{
	return (_strtof(s, endptr));
}

__attribute__((__optimize__("Ofast"),__flatten__))
float	ft_strtof(char *restrict s, char **restrict endptr)
{
	return (_strtof(s, endptr));
}
