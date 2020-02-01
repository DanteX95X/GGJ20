#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>

namespace godot
{
	class PlayerController : public godot::Node2D
	{
		GODOT_CLASS(PlayerController, godot::Node2D)

	public:
		static void _register_methods();

		PlayerController();
		~PlayerController();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		Ref<PackedScene> nail;
	};
}

#endif // PLAYER_CONTROLLER_H
