#include "block_parent.h"
#include <Input.hpp>
#include <RigidBody2D.hpp>

namespace godot
{
	void BlockParent::_register_methods()
	{
		godot::register_method("_ready", &BlockParent::_ready);
		godot::register_method("_process", &BlockParent::_process);

		godot::register_method("EnableGravity", &BlockParent::EnableGravityInChildren);
	}

	BlockParent::BlockParent()
	{
	}

	BlockParent::~BlockParent()
	{
	}

	void BlockParent::_init()
	{
	}

	void BlockParent::_ready()
	{
	}

	void BlockParent::_process(float delta)
	{
	}

	void BlockParent::EnableGravityInChildren()
	{
		for(int i = 0; i < get_child_count(); ++i)
		{
			static_cast<RigidBody2D*>(get_child(i))->set_mode(RigidBody2D::MODE_RIGID);
		}
	}
}
