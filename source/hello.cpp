#include "hello.h"

namespace test
{
	void Hello::_register_methods()
	{
		register_method("_process", &Hello::_process);
	}

	Hello::Hello()
	{
	}

	Hello::~Hello()
	{
	}

	void Hello::_init()
	{
	}

	void Hello::_process(float delta)
	{
	}
}