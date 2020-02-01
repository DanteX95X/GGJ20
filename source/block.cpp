#include "block.h"

#include <Input.hpp>
#include "player_controller.h"

namespace godot
{
	void Block::_register_methods()
	{
		godot::register_method("_ready", &Block::_ready);
		godot::register_method("_process", &Block::_process);
		godot::register_method("OnInputEvent", &Block::OnInputEvent);
		godot::register_method("ExplosionImpact", &Block::ExplosionImpact);

		godot::register_property<Block, bool>("isStaticBlock", &Block::isStaticBlock, false);
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
		if(this->exploded)
		{
			this->timeAfterExplosion += delta;
		}

		if(this->timeAfterExplosion > 1.5)
		{
			timeAfterExplosion = 0;
			exploded = false;
			this->set_linear_velocity(Vector2(0,0));
			this->set_applied_force(Vector2(0,0));

			this->set_mode(RigidBody2D::MODE_STATIC);
		}

		if (dragging)
		{
			Vector2 diff(get_global_mouse_position() - lastMousePosition);
			this->set_global_position(get_global_position() + diff);
			lastMousePosition = get_global_mouse_position();

			if(Input::get_singleton()->is_action_just_released("drag_block"))
			{
				dragging = false;
				Godot::print("End dragging");
			}

			// rotating
			if(Input::get_singleton()->is_action_pressed("rotate_left"))
			{
				Godot::print("Rotate left");
				set_global_rotation_degrees(get_global_rotation_degrees() - 3);
			}
			else if(Input::get_singleton()->is_action_pressed("rotate_right"))
				set_global_rotation_degrees(get_global_rotation_degrees() + 3);
		}
	}

	void Block::DisableDrag()
	{
		this->disconnect("input_event", this, "OnInputEvent");
	}

	void Block::OnInputEvent(const Node* camera, const Ref<InputEvent> event, Vector3 click_position, Vector3 click_normal, int shape_idx)
	{
		if(!this->isStaticBlock)
		{
			if(Input::get_singleton()->is_action_just_pressed("drag_block"))
			{
				dragging = true;

				lastMousePosition = get_global_mouse_position();

				this->set_z_index(++PlayerController::zOrder);

				Godot::print("Start dragging");
			}
		}
	}

	void Block::ExplosionImpact(Vector2 center)
	{
		godot::Godot::print("Explosionimpact!");
		if(!isStaticBlock){
			this->set_mode(RigidBody2D::MODE_RIGID);
			Vector2 diff = center - this->get_global_position();
			diff.normalize();
			this->apply_central_impulse(diff * -1000);
			this->exploded = true;
			this->set_z_index(++PlayerController::zOrder);
		}
	}
}
