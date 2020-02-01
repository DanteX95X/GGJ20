#ifndef BLOCK_H
#define BLOCK_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <RigidBody2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>

namespace godot
{
	class Block : public godot::RigidBody2D
	{
		GODOT_CLASS(Block, godot::RigidBody2D)

	public:
		static void _register_methods();

		Block();
		~Block();

		void _init();
		void _ready();
		void _process(float delta);

		void DisableDrag();

		void OnInputEvent(const Node* camera, const Ref<InputEvent> event, Vector3 click_position, Vector3 click_normal, int shape_idx);
		void ExplosionImpact(Vector2 center);

	private:
		bool isStaticBlock{false};
		bool exploded{false};
		float timeAfterExplosion{0.0f};

		Vector2 lastMousePosition{};
		bool dragging = false;
	};
}

#endif // BLOCK_H
