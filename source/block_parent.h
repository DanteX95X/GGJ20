#ifndef BLOCK_PARENT_H
#define BLOCK_PARENT_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class BlockParent : public godot::Node2D
	{
		GODOT_CLASS(BlockParent, godot::Node2D)

	public:
		static void _register_methods();

		BlockParent();
		~BlockParent();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		void EnableGravityInChildren();
	};
}

#endif // BLOCK_PARENT_H
