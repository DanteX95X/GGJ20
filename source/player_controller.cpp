#include "player_controller.h"

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
	}
}
