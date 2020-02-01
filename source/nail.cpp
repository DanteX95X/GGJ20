#include "nail.h"
#include <PinJoint2D.hpp>
#include <RigidBody2D.hpp>
#include <ResourceLoader.hpp>

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
	}

	void Nail::OnBodyEntered(PhysicsBody2D* body)
	{
		if(!previouslyEnteredBodies.empty())
		{
			for(int i = 0; i < previouslyEnteredBodies.size(); ++i)
			{
				PinJoint2D* pin = PinJoint2D::_new();
				RigidBody2D* previouslyEnteredBody = static_cast<RigidBody2D*>(previouslyEnteredBodies[i]);
				this->add_child(pin);
				pin->set_node_a(previouslyEnteredBody->get_path());
				pin->set_node_b(body->get_path());

				previouslyEnteredBody->set_gravity_scale(5);
			}
		}

		PinJoint2D* pin = PinJoint2D::_new();
		this->add_child(pin);
		pin->set_node_a(body->get_path());
		pin->set_node_b(nailBody->get_path());

		previouslyEnteredBodies.append(body);
	}
}
