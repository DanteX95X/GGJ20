#include "player_controller.h"
#include "Input.hpp"
#include <ResourceLoader.hpp>
#include <Input.hpp>
#include <Viewport.hpp>
#include <Area2D.hpp>

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
		Ref<Resource> resource = ResourceLoader::get_singleton()->load("res://scenes/actors/nail.tscn");
		nail = resource;
	}

	void PlayerController::_ready()
	{
	}

	void PlayerController::_process(float delta)
	{
		Vector2 mousePosition = this->get_local_mouse_position();

		if(input->is_action_just_released("place_nail"))
		{
			Node* instance = nail->instance();
			Node2D* node = static_cast<Node2D*>(instance);
			node->set_position(mousePosition);
			add_child(node);
		}
	}
}
