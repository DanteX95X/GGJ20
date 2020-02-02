#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>

namespace godot
{
	class PlayerController : public godot::Node2D
	{
		GODOT_CLASS(PlayerController, godot::Node2D)

	public:
		static void _register_methods();

		PlayerController();
		~PlayerController();

		void _init();
		void _ready();
		void _process(float delta);

		void CheckWinCondition();
		void SuccessChanged(bool value);

		void GameOver(bool win);

		static int64_t zOrder;

	private:
		Ref<PackedScene> nail{};

		int remainingNails{10};
		bool exploded{false};
		float timeAfterExplosion{0.0f};
		bool placingStarted{false};
		bool checkWin{false};
		int successes = 0;
		float time = 0;

		void Explode();
	};
}

#endif // PLAYER_CONTROLLER_H
