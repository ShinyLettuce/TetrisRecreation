#include "math_util.h"

int wrap_index(int i, int i_mod)
{
	i = i % i_mod;
	return i < 0 ? i + i_mod : i;
}