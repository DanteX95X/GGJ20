#ifndef NAIL_H
#define NAIL_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Area2D.hpp>
#include <RigidBody2D.hpp>
#include <PackedScene.hpp>

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

	private:
		void OnBodyEntered(PhysicsBody2D* area);

		RigidBody2D* nailBody{nullptr};
	};
}

#endif // NAIL_H
