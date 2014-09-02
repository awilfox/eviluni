#include <unicode/uspoof.h>
#include <stdbool.h>	// bool, true, false
#include <stdint.h>	// int32_t

USpoofChecker *__checker;

bool spoof_init(void)
{
	UErrorCode err = 0;

	if(__checker != NULL)
	{
		// Don't double-init
		return true;
	}

	__checker = uspoof_open(&err);
	if(err != 0 || __checker == NULL)
	{
		return false;
	}
	uspoof_setRestrictionLevel(__checker, USPOOF_HIGHLY_RESTRICTIVE);
	uspoof_setChecks(__checker, USPOOF_MIXED_SCRIPT_CONFUSABLE | USPOOF_RESTRICTION_LEVEL, &err);
	if(err != 0)
	{
		uspoof_close(__checker);
		__checker = NULL;
		return false;
	}

	return true;
}

int32_t spoof_is_evil(const char *string)
{
	UErrorCode err = 0;
	int32_t evilness;

	if(__checker == NULL)
	{
		if(!spoof_init())
		{
			return -1;
		}
	}

	evilness = uspoof_checkUTF8(__checker, string, -1, NULL, &err);
	if(err != 0)
	{
		return -1;
	}

	return evilness;
}

