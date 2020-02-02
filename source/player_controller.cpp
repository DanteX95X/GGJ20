#include "player_controller.h"
#include "Input.hpp"
#include "block.h"
#include <ResourceLoader.hpp>
#include <AudioStreamPlayer.hpp>
#include <Input.hpp>
#include <Label.hpp>
#include <Viewport.hpp>
#include <Area2D.hpp>
#include <SceneTree.hpp>
#include "block_parent.h"
#include "win_condition.h"
#include <Node.hpp>
#include <Particles2D.hpp>

#include <string>

namespace godot
{
	int64_t PlayerController::zOrder = 0;

	void PlayerController::_register_methods()
	{
		godot::register_method("_ready", &PlayerController::_ready);
		godot::register_method("_process", &PlayerController::_process);

		godot::register_method("CheckWinCondition", &PlayerController::CheckWinCondition);
		godot::register_method("SuccessChanged", &PlayerController::SuccessChanged);
		godot::register_method("GameOver", &PlayerController::GameOver);

		godot::register_property<PlayerController, int>("Nails", &PlayerController::remainingNails, 10);

		godot::register_signal<PlayerController>("game_over", "win", GODOT_VARIANT_TYPE_BOOL);
		godot::register_signal<PlayerController>("level_ready", Dictionary());
		godot::register_signal<PlayerController>("simulation_started", Dictionary());
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
		SetNailsLabelValue();

		Node* playButton = get_node("PlayButton");
		BlockParent* blockParent = static_cast<BlockParent*>(get_node("BlockParent"));
		playButton->connect("play_physics", blockParent, "EnableGravity");
		playButton->connect("play_physics", this, "CheckWinCondition");
		connect("game_over", playButton, "OnGameOver");
		connect("game_over", this, "GameOver");
		connect("level_ready", playButton, "OnLevelReady");

		animator = static_cast<AnimationPlayer*>(get_node("HammerAnimation"));
	}

	void PlayerController::_process(float delta)
	{
		Vector2 mousePosition = this->get_local_mouse_position();

		const auto& input = Input::get_singleton();

		if(checkWin)
		{
			time += delta;
			if(time >= 5)
			{
				time = 0;
				checkWin = false;

				int required = get_node("Conditions")->get_child_count();

				emit_signal("game_over", successes == required);
			}
		}

		if(!this->placingStarted)
		{
			time += delta;

			if(time >= 3)
			{
				time = 0;
				this->placingStarted = true;
				this->Explode();
				emit_signal("level_ready");
			}
		}

		if(this->placingStarted)
		{
			nailTime += delta;

			if(nailTime > 1 && input->is_action_just_released("place_nail") && this->remainingNails > 0)
			{
				nailTime = 0;
				animator->play("HammerAnimation");
				this->remainingNails -= 1;
				godot::Godot::print("Nails reminding: {0}", this->remainingNails);
				Node* instance = nail->instance();
				Node2D* node = static_cast<Node2D*>(instance);
				node->set_z_index(++PlayerController::zOrder);
				node->set_position(mousePosition);
				add_child(node);

				SetNailsLabelValue();

				auto hammer = static_cast<Node2D*>(animator->get_node("Hammer"));
				hammer->set_global_position(get_global_mouse_position() + Vector2{100, -40});
				hammer->set_z_index(PlayerController::zOrder + 1);
			}
		}
	}

	void PlayerController::SetNailsLabelValue()
	{
		Node* playButton = static_cast<Node*>(this->get_node("PlayButton"));
		if (playButton != nullptr)
		{
			Label* nailsValue = static_cast<Label*>(playButton->get_node("NailsValue"));
			if(nailsValue != nullptr)
			{
				nailsValue->set_text(std::to_string(this->remainingNails).c_str());
			}
		}
	}

	void PlayerController::Explode()
	{
		BreakToy();
		auto children = this->get_node("BlockParent")->get_children();
		auto background_position = static_cast<Node2D*>(this->get_node("backgroundRB"))->get_position();

		for (int i = 0; i < children.size(); i++)
		{
			Block* block = static_cast<Block*>(children[i]);
			if(block != nullptr)
			{
				block->ExplosionImpact(background_position);
			}
		}
	}

	void PlayerController::LevelSuccess()
	{
		auto playButton = this->get_node("PlayButton");
		static_cast<AudioStreamPlayer*>(playButton->get_node("kidsSound"))->play();
	}

	void PlayerController::LevelFailed()
	{
		auto playButton = this->get_node("PlayButton");
		static_cast<AudioStreamPlayer*>(playButton->get_node("crowdSound"))->play();
    }

	void PlayerController::PlayDrums()
	{
		auto playButton = this->get_node("PlayButton");
		static_cast<AudioStreamPlayer*>(playButton->get_node("drumrollSound"))->play();
	}

	void PlayerController::BreakToy()
	{
		auto playButton = this->get_node("PlayButton");
		static_cast<AudioStreamPlayer*>(playButton->get_node("brokeSound"))->play();
		Particles2D* particles = static_cast<Particles2D*>(playButton->get_node("ExplosionParticles"));
		particles->set_emitting(true);
		auto background_position = static_cast<Node2D*>(this->get_node("backgroundRB"))->get_global_position();
		particles->set_global_position(background_position);
	}

	void PlayerController::CheckWinCondition()
	{
		PlayDrums();
		emit_signal("simulation_started");

		checkWin = true;
		time = 0;

		Node* node = get_node("Conditions");

		for(int i = 0; i < node->get_child_count(); ++i)
		{
			WinCondition* condition = static_cast<WinCondition*>(node->get_child(i));
			condition->connect("body_entered", condition, "OnBodyEntered");
			condition->connect("body_exited", condition, "OnBodyExited");
			condition->connect("success_changed", this, "SuccessChanged");
		}
	}

	void PlayerController::SuccessChanged(bool value)
	{
		if(value)
		{
			Godot::print("+1");
			++successes;
		}
		else
		{
			Godot::print("-1");
			--successes;
		}
	}

	void PlayerController::GameOver(bool win)
	{
		if(win)
        {
			Godot::print("win");
            LevelSuccess();
        }
		else
        {
			Godot::print("raptot zjebałeś");
            LevelFailed();
        }
	}
}
