#include <stdio.h>
#include "testfunction.h"
#include "stub.h"

extern int isCalibMedSpecialTonerFill(void);
static int Test_Function(void);

int Test_Function(void)
{
	if( isCalibMedSpecialTonerFill() == 1 )
	{
		return 1;
	}
	else	
	{
		return 0;
	}
}
