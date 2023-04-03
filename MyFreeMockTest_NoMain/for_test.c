#include "for_test.h"
//#include "stub.h"

int For_Test(void)
{
	ForStub();
	test_test();
	if( ForStub() == 1 )
	{
		return 1;
	}
	else	
	{
		return 0;
	}

}

int ForStub(void)
{
	if(this_is_param(1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int this_is_param(int data)
{
	if(data == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}