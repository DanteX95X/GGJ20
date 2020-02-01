#include "player_controller.h"
#include "Input.hpp"

namespace godot
{
	void PlayerController::_register_methods()
	{
		godot::register_method("_ready", &PlayerController::_ready);
		godot::register_method("_process", &PlayerController::_process);
	}

	PlayerController::PlayerController()
	{
	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::_init()
	{
	}

	void PlayerController::_ready()
	{
	}

	void PlayerController::_process(float delta)
	{
		auto input = Input::get_singleton();
		bool nail_pressed = input->is_action_pressed("place_nail");

		if(nail_pressed)
			godot::Godot::print("{0}", nail_pressed);
	}
}
