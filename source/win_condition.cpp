#include "win_condition.h"

namespace godot
{
	void WinCondition::_register_methods()
	{
		godot::register_method("_ready", &WinCondition::_ready);
		godot::register_method("_process", &WinCondition::_process);

		godot::register_method("OnBodyEntered", &WinCondition::OnBodyEntered);
		godot::register_method("OnBodyExited", &WinCondition::OnBodyExited);

		godot::register_property<WinCondition, String>("ProperBlockName", &WinCondition::properBlockName, "Kurwa");

		Dictionary args;
		args[godot::Variant("success")] = godot::Variant(godot::Variant::BOOL);
		godot::register_signal<WinCondition>("success_changed", "success", GODOT_VARIANT_TYPE_BOOL);
	}

	WinCondition::WinCondition()
	{
	}

	WinCondition::~WinCondition()
	{
	}

	void WinCondition::_init()
	{
	}

	void WinCondition::_ready()
	{
	}

	void WinCondition::_process(float delta)
	{
	}

	void WinCondition::OnBodyEntered(PhysicsBody2D* body)
	{
		if(body->get_name().find(properBlockName) != -1)
		{
			Godot::print("entered");
			emit_signal("success_changed", true);
		}
	}

	void WinCondition::OnBodyExited(PhysicsBody2D* body)
	{
		if(body->get_name().find(properBlockName != -1))
		{
			Godot::print("exited");
			emit_signal("success_changed", false);
		}
	}
}
