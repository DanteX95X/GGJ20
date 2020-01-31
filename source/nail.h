#ifndef NAIL_H
#define NAIL_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Area2D.hpp>

namespace godot
{
	class Nail : public godot::Area2D
	{
		GODOT_CLASS(Nail, godot::Area2D)

	public:
		static void _register_methods();

		Nail();
		~Nail();

		void _init();
		void _ready();
		void _process(float delta);

		void OnAreaEntered(Area2D* area);

	};
}

#endif // NAIL_H
