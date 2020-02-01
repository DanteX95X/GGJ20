#include "nail.h"

namespace godot
{
	void Nail::_register_methods()
	{
		godot::register_method("_ready", &Nail::_ready);
		godot::register_method("_process", &Nail::_process);

		godot::register_method("OnAreaEntered", &Nail::OnAreaEntered);
	}

	Nail::Nail()
	{
	}

	Nail::~Nail()
	{
	}

	void Nail::_init()
	{
	}

	void Nail::_ready()
	{
		this->connect("area_entered", this, "OnAreaEntered");
	}

	void Nail::_process(float delta)
	{
	}

	void Nail::OnAreaEntered(Area2D* area)
	{
		Node* node = area->get_node("Sprite");

		if(node != nullptr)
		{
			Godot::print("git");
		}
	}
}
