#include "block.h"

namespace godot
{
	void Block::_register_methods()
	{
		godot::register_method("_ready", &Block::_ready);
		godot::register_method("_process", &Block::_process);
	}

	Block::Block()
	{
	}

	Block::~Block()
	{
	}

	void Block::_init()
	{
	}

	void Block::_ready()
	{
		Godot::print("Block ready");
	}

	void Block::_process(float delta)
	{
	}
}
