#ifndef BLOCK_H
#define BLOCK_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class Block : public godot::Node2D
	{
		GODOT_CLASS(Block, godot::Node2D)

	public:
		static void _register_methods();

		Block();
		~Block();

		void _init();
		void _ready();
		void _process(float delta);
	};
}

#endif // BLOCK_H
