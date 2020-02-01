#include "nail.h"
#include <PinJoint2D.hpp>
#include <RigidBody2D.hpp>
#include <ResourceLoader.hpp>

#include "block.h"

namespace godot
{
	void Nail::_register_methods()
	{
		godot::register_method("_ready", &Nail::_ready);
		godot::register_method("_process", &Nail::_process);

		godot::register_method("OnBodyEntered", &Nail::OnBodyEntered);
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
		this->connect("body_entered", this, "OnBodyEntered");
		nailBody = static_cast<RigidBody2D*>(this->get_node("Body"));
	}

	void Nail::_process(float delta)
	{
		if(didResolveCollision)
			canResolveCollisions = false;
	}

	void Nail::OnBodyEntered(PhysicsBody2D* body)
	{
		if(canResolveCollisions)
		{
			didResolveCollision = true;
			PinJoint2D* pin = PinJoint2D::_new();
			this->add_child(pin);
			pin->set_node_a(body->get_path());
			pin->set_node_b(nailBody->get_path());
		}
	}
}
