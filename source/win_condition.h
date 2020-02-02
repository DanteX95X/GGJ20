#ifndef WIN_CONDITION_H
#define WIN_CONDITION_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PhysicsBody2D.hpp>

namespace godot
{
	class WinCondition : public godot::Node2D
	{
		GODOT_CLASS(WinCondition, godot::Node2D)

	public:
		static void _register_methods();

		WinCondition();
		~WinCondition();

		void _init();
		void _ready();
		void _process(float delta);

		void OnBodyEntered(PhysicsBody2D* body);
		void OnBodyExited(PhysicsBody2D* body);

	private:
		String properBlockName = "";
	};
}

#endif // WIN_CONDITION_H
