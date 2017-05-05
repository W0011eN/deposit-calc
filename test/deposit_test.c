#include <ctest.h>
#include "deposit.h"

CTEST(deposit_test, simle_sum)
{
	const int pod = 5;
	const float deposit = 99999;

	const float result = income_deposit(deposit, pod);

	const float sum = 90009;
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_0_30_min_deposit)
{
	const int pod = 0;
	const float deposit = 10000;

	const float result = income_deposit(deposit, pod);

	const float sum = 9000;
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_0_30_deposit)
{
	const int pod = 30;
	const float deposit = 100000;

	const float result = income_deposit(deposit, pod);

	const float sum = 90000;
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_31_120_min_deposit)
{
	const int pod = 31;
	const float deposit = 10000;

	const float result = income_deposit(deposit, pod);

	const float sum = 10200;
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_31_120_deposit)   //Ошибка
{
	const int pod = 120;
	const float deposit = 100000;

	const float result = income_deposit(deposit, pod);

	const float sum = 103000;  //102000
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_121_240_min_deposit)
{
	const int pod = 121;
	const float deposit = 10000;

	const float result = income_deposit(deposit, pod);

	const float sum = 10600;
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_121_240_deposit) //Ошибка
{
	const int pod = 240;
	const float deposit = 100000;

	const float result = income_deposit(deposit, pod);

	const float sum = 108000;		//106000
	ASSERT_DBL_NEAR(sum, result);
}

CTEST(deposit_test, time_241_365_min_deposit)
{
	const int pod = 241;
	const float deposit = 10000;

	const float result = income_deposit(deposit, pod);

	const float sum = 11200;
	ASSERT_DBL_NEAR(sum, result);
}


