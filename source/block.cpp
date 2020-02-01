#include "block.h"

#include <Input.hpp>

namespace godot
{
	void Block::_register_methods()
	{
		godot::register_method("_ready", &Block::_ready);
		godot::register_method("_process", &Block::_process);
		godot::register_method("OnInputEvent", &Block::OnInputEvent);
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
		this->connect("input_event", this, "OnInputEvent");
	}

	void Block::_process(float delta)
	{
		if (dragging)
		{
			Vector2 diff(get_local_mouse_position() - lastMousePosition);
			set_position(get_position() + diff);
			lastMousePosition = get_local_mouse_position();
		}
	}

	void Block::OnInputEvent(const Node* camera, const Ref<InputEvent> event, Vector3 click_position, Vector3 click_normal, int shape_idx)
	{
		if(Input::get_singleton()->is_action_just_pressed("drag_block"))
		{
			dragging = true;

			lastMousePosition = get_local_mouse_position();

			Godot::print("Start dragging");
		}
		else if(Input::get_singleton()->is_action_just_released("drag_block"))
		{
			dragging = false;

			Godot::print("End dragging");
		}
	}
}
