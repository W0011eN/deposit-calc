#include <ctest.h>
#include "deposit.h"

CTEST(deposit_test, test_1)
{
	const int pod = 365;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = 0;
	ASSERT_EQUAL(counter_check, result);

	
}

CTEST(deposit_test, time_deposit_exit)
{
	const int pod = 366;
	const int deposit = 9999;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(deposit_test, time_exit)
{
	const int pod = 366;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(deposit_test, deposit_exit)
{
	const int pod = 365;
	const int deposit = 9999;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}

CTEST(deposit_test, time_negative)
{
	const int pod = -1;
	const int deposit = 10000;

	const int result = vapod(deposit, pod);

	const int counter_check = -1;
	ASSERT_EQUAL(counter_check, result);
}
