#include <ctest.h>
#include "deposit.h"

CTEST(arithmetic_suite, test_1)
{
	const int pod = 365;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = 0;
	ASSERT_EQUAL(counter_check, result);

	
}

CTEST(arithmetic_suite, time_deposit_exit)
{
	const int pod = 366;
	const int deposit = 9999;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(arithmetic_suite, time_exit)
{
	const int pod = 366;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(arithmetic_suite, deposit_exit)
{
	const int pod = 365;
	const int deposit = 9999;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(arithmetic_suite, time_negative)
{
	const int pod = -1;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}