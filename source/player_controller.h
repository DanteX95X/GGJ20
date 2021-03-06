#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <AnimationPlayer.hpp>

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

		void LevelSuccess();
		void LevelFailed();
		void PlayDrums();
		void BreakToy();

	private:
		Ref<PackedScene> nail{};

		void SetNailsLabelValue();

		int remainingNails{10};
		bool exploded{false};
		float timeAfterExplosion{0.0f};
		bool placingStarted{false};
		bool checkWin{false};
		int successes = 0;
		float time = 0;
		float nailTime = 0;

		AnimationPlayer* animator;

		void Explode();
	};
}

#endif // PLAYER_CONTROLLER_H
