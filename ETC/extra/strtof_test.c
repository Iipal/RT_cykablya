#include "strtof.h"
#include "assert.h"

# pragma GCC diagnostic ignored "-Wfloat-equal"

extern float
__attribute__((__nonnull__(1)))
strtof(const char *restrict, char **restrict);

void		TEST_strtof_main(void);

void		TEST_strtof_main(void)
{
	char *restrict tst = (char[]){ "-inf +2.5E-1 " };
	char * endptr;

	assert(O_strtof(tst, &endptr) == -__builtin_inff());
	tst = endptr;
	assert(O_strtof(tst, &endptr) == 0.25000000f);


	assert(O_strtof((char[]){ "-inf" }, (char**)0) == -__builtin_inff());
	assert(o_strtof((char[]){ "inf" }, (char**)0) == __builtin_inff());
	{
		assert(O_strtof((char[]){ "" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "0" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "0.0" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "0." }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ ".0" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "1" }, (char**)0) == 1.0000000f);
		assert(O_strtof((char[]){ ".5" }, (char**)0) == 0.50000000f);
		assert(O_strtof((char[]){ "1.5" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "+1" }, (char**)0) == 1.0000000f);
		assert(O_strtof((char[]){ "+.5" }, (char**)0) == 0.50000000f);
		assert(O_strtof((char[]){ "+1.5" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "-1" }, (char**)0) == -1.0000000f);
		assert(O_strtof((char[]){ "-.5" }, (char**)0) == -0.50000000f);
		assert(O_strtof((char[]){ "-1.5" }, (char**)0) == -1.5000000f);
		
		assert(O_strtof((char[]){ "1.2345678" }, (char**)0) == 1.2345678f);
		assert(O_strtof((char[]){ "0.99999995" }, (char**)0) == 0.99999994f);
		assert(O_strtof((char[]){ "0.99999998" }, (char**)0) == 1.0000000f);
		assert(O_strtof((char[]){ "1.0000001" }, (char**)0) == 1.0000001f);
		assert(O_strtof((char[]){ "1.00000000001" }, (char**)0) == 1.0000000f);

		assert(O_strtof((char[]){ "1e1" }, (char**)0) == 10.000000f);
		assert(O_strtof((char[]){ "1e+1" }, (char**)0) == 10.000000f);
		assert(O_strtof((char[]){ "5e-1" }, (char**)0) == 0.50000000f);
		assert(O_strtof((char[]){ "1.5e1" }, (char**)0) == 15.000000f);
		assert(O_strtof((char[]){ "1.5e+1" }, (char**)0) == 15.000000f);
		assert(O_strtof((char[]){ "2.5e-1" }, (char**)0) == 0.25000000f);
		assert(O_strtof((char[]){ "1E1" }, (char**)0) == 10.000000f);
		assert(O_strtof((char[]){ "1E+1" }, (char**)0) == 10.000000f);
		assert(O_strtof((char[]){ "5E-1" }, (char**)0) == 0.50000000f);
		assert(O_strtof((char[]){ "1.5E1" }, (char**)0) == 15.000000f);
		assert(O_strtof((char[]){ "1.5E+1" }, (char**)0) == 15.000000f);
		assert(O_strtof((char[]){ "2.5E-1" }, (char**)0) == 0.25000000f);

		assert(O_strtof((char[]){ "inf" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "Inf" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "INF" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "+inf" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "+Inf" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "-inf" }, (char**)0) == -__builtin_inff());
		assert(O_strtof((char[]){ "-Inf" }, (char**)0) == -__builtin_inff());
		assert(O_strtof((char[]){ "-INF" }, (char**)0) == -__builtin_inff());
		assert(O_strtof((char[]){ "inf5" }, (char**)0) == __builtin_inff());
		assert(O_strtof((char[]){ "inf.5" }, (char**)0) == __builtin_inff());

		assert(O_strtof((char[]){ "10000000000000000000000000000000000000000" }, (char**)0) == __builtin_huge_valf());
		assert(O_strtof((char[]){ "0.0000000000000000000000000000000000000001" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "1e40" }, (char**)0) == __builtin_huge_valf());
		assert(O_strtof((char[]){ "1e-40" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "1e4000" }, (char**)0) == __builtin_huge_valf());
		assert(O_strtof((char[]){ "1e-4000" }, (char**)0) == 0.0f);
		assert(O_strtof((char[]){ "10000000e33" }, (char**)0) == __builtin_huge_valf());
		assert(O_strtof((char[]){ "0.0000001e-33" }, (char**)0) == 0.0f);

		assert(O_strtof((char[]){ "0.0000001e40" }, (char**)0) == 1.0000000e33f);
		assert(O_strtof((char[]){ "10000000e-40" }, (char**)0) == 1.0000000e-33f);

		assert(O_strtof((char[]){ "3.4028235e+38" }, (char**)0) == 3.4028235e+38f);
		assert(O_strtof((char[]){ "3.4028238e+38" }, (char**)0) == __builtin_huge_valf());
		assert(O_strtof((char[]){ "1.1754944e-38" }, (char**)0) == 1.1754944e-38f);
		//assert(O_strtof((char[]){ "1.1754941e-38" }, (char**)0) == 0.0f);
		//__builtin_printf("%.50f\n", O_strtof((char[]){ "1.1754944e-38" }, (char**)0));

		assert(O_strtof((char[]){ " 1.5" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "   1.5" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "\t1.5" }, (char**)0) != 1.5000000f);
		assert(O_strtof((char[]){ "\n1.5" }, (char**)0) != 1.5000000f);
		assert(O_strtof((char[]){ "_1.5" }, (char**)0) != 1.5000000f);


		assert(O_strtof((char[]){ "1.5 " }, (char**)0) == 1.5000000f);

		assert(O_strtof((char[]){ "1.5.2" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5e1.2" }, (char**)0) == 15.000000f);
		assert(O_strtof((char[]){ "1.5z" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5e1z" }, (char**)0) == 15.000000f);

		assert(O_strtof((char[]){ "ing" }, (char**)0) != __builtin_inff());
		assert(O_strtof((char[]){ "Ing" }, (char**)0) != __builtin_inff());
		assert(O_strtof((char[]){ "INg" }, (char**)0) != __builtin_inff());
		assert(O_strtof((char[]){ "io" }, (char**)0) != __builtin_inff());
		assert(O_strtof((char[]){ "Io" }, (char**)0) != __builtin_inff());

		assert(O_strtof((char[]){ "1.5ez" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5E!" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5e+z" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5E+!" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5e-z" }, (char**)0) == 1.5000000f);
		assert(O_strtof((char[]){ "1.5E-!" }, (char**)0) == 1.5000000f);
	}

	{
		assert(o_strtof((char[]){ "" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "0" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "0.0" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "0." }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ ".0" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "1" }, (char**)0) == 1.0000000f);
		assert(o_strtof((char[]){ ".5" }, (char**)0) == 0.50000000f);
		assert(o_strtof((char[]){ "1.5" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "+1" }, (char**)0) == 1.0000000f);
		assert(o_strtof((char[]){ "+.5" }, (char**)0) == 0.50000000f);
		assert(o_strtof((char[]){ "+1.5" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "-1" }, (char**)0) == -1.0000000f);
		assert(o_strtof((char[]){ "-.5" }, (char**)0) == -0.50000000f);
		assert(o_strtof((char[]){ "-1.5" }, (char**)0) == -1.5000000f);
		
		assert(o_strtof((char[]){ "1.2345678" }, (char**)0) == 1.2345678f);
		assert(o_strtof((char[]){ "0.99999995" }, (char**)0) == 0.99999994f);
		assert(o_strtof((char[]){ "0.99999998" }, (char**)0) == 1.0000000f);
		assert(o_strtof((char[]){ "1.0000001" }, (char**)0) == 1.0000001f);
		assert(o_strtof((char[]){ "1.00000000001" }, (char**)0) == 1.0000000f);

		assert(o_strtof((char[]){ "1e1" }, (char**)0) == 10.000000f);
		assert(o_strtof((char[]){ "1e+1" }, (char**)0) == 10.000000f);
		assert(o_strtof((char[]){ "5e-1" }, (char**)0) == 0.50000000f);
		assert(o_strtof((char[]){ "1.5e1" }, (char**)0) == 15.000000f);
		assert(o_strtof((char[]){ "1.5e+1" }, (char**)0) == 15.000000f);
		assert(o_strtof((char[]){ "2.5e-1" }, (char**)0) == 0.25000000f);
		assert(o_strtof((char[]){ "1E1" }, (char**)0) == 10.000000f);
		assert(o_strtof((char[]){ "1E+1" }, (char**)0) == 10.000000f);
		assert(o_strtof((char[]){ "5E-1" }, (char**)0) == 0.50000000f);
		assert(o_strtof((char[]){ "1.5E1" }, (char**)0) == 15.000000f);
		assert(o_strtof((char[]){ "1.5E+1" }, (char**)0) == 15.000000f);
		assert(o_strtof((char[]){ "2.5E-1" }, (char**)0) == 0.25000000f);

		assert(o_strtof((char[]){ "inf" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "Inf" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "INF" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "+inf" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "+Inf" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "-inf" }, (char**)0) == -__builtin_inff());
		assert(o_strtof((char[]){ "-Inf" }, (char**)0) == -__builtin_inff());
		assert(o_strtof((char[]){ "-INF" }, (char**)0) == -__builtin_inff());
		assert(o_strtof((char[]){ "inf5" }, (char**)0) == __builtin_inff());
		assert(o_strtof((char[]){ "inf.5" }, (char**)0) == __builtin_inff());

		assert(o_strtof((char[]){ "10000000000000000000000000000000000000000" }, (char**)0) == __builtin_huge_valf());
		assert(o_strtof((char[]){ "0.0000000000000000000000000000000000000001" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "1e40" }, (char**)0) == __builtin_huge_valf());
		assert(o_strtof((char[]){ "1e-40" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "1e4000" }, (char**)0) == __builtin_huge_valf());
		assert(o_strtof((char[]){ "1e-4000" }, (char**)0) == 0.0f);
		assert(o_strtof((char[]){ "10000000e33" }, (char**)0) == __builtin_huge_valf());
		assert(o_strtof((char[]){ "0.0000001e-33" }, (char**)0) == 0.0f);

		assert(o_strtof((char[]){ "0.0000001e40" }, (char**)0) == 1.0000000e33f);
		assert(o_strtof((char[]){ "10000000e-40" }, (char**)0) == 1.0000000e-33f);

		assert(o_strtof((char[]){ "3.4028235e+38" }, (char**)0) == 3.4028235e+38f);
		assert(o_strtof((char[]){ "3.4028238e+38" }, (char**)0) == __builtin_huge_valf());
		assert(o_strtof((char[]){ "1.1754944e-38" }, (char**)0) == 1.1754944e-38f);
		//assert(o_strtof((char[]){ "1.1754941e-38" }, (char**)0) == 0.0f);
		//__builtin_printf("%.50f\n", o_strtof((char[]){ "1.1754944e-38" }, (char**)0));

		assert(o_strtof((char[]){ " 1.5" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "   1.5" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "\t1.5" }, (char**)0) != 1.5000000f);
		assert(o_strtof((char[]){ "\n1.5" }, (char**)0) != 1.5000000f);
		assert(o_strtof((char[]){ "_1.5" }, (char**)0) != 1.5000000f);


		assert(o_strtof((char[]){ "1.5 " }, (char**)0) == 1.5000000f);

		assert(o_strtof((char[]){ "1.5.2" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5e1.2" }, (char**)0) == 15.000000f);
		assert(o_strtof((char[]){ "1.5z" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5e1z" }, (char**)0) == 15.000000f);

		assert(o_strtof((char[]){ "ing" }, (char**)0) != __builtin_inff());
		assert(o_strtof((char[]){ "Ing" }, (char**)0) != __builtin_inff());
		assert(o_strtof((char[]){ "INg" }, (char**)0) != __builtin_inff());
		assert(o_strtof((char[]){ "io" }, (char**)0) != __builtin_inff());
		assert(o_strtof((char[]){ "Io" }, (char**)0) != __builtin_inff());

		assert(o_strtof((char[]){ "1.5ez" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5E!" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5e+z" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5E+!" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5e-z" }, (char**)0) == 1.5000000f);
		assert(o_strtof((char[]){ "1.5E-!" }, (char**)0) == 1.5000000f);
	}

# pragma GCC diagnostic error "-Wfloat-equal"

	__builtin_printf("DONE!\n");

}
