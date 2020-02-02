#include "player_controller.h"
#include "Input.hpp"
#include "block.h"
#include <ResourceLoader.hpp>
#include <Input.hpp>
#include <Viewport.hpp>
#include <Area2D.hpp>
#include <SceneTree.hpp>
#include "block_parent.h"
#include "win_condition.h"
#include <Node.hpp>

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
		Node* playButton = get_node("PlayButton");
		BlockParent* blockParent = static_cast<BlockParent*>(get_node("BlockParent"));
		playButton->connect("play_physics", blockParent, "EnableGravity");
		playButton->connect("play_physics", this, "CheckWinCondition");
		connect("game_over", this, "GameOver");
	}

	void PlayerController::_process(float delta)
	{
		Vector2 mousePosition = this->get_local_mouse_position();

		const auto& input = Input::get_singleton();

		if(checkWin)
		{
			time += delta;
			if(time >= 1.5f)
			{
				checkWin = false;

				int required = get_node("Conditions")->get_child_count();

				emit_signal("game_over", successes == required);
			}
		}

		if(!this->placingStarted && input->is_action_just_released("start_level"))
		{
			this->placingStarted = true;
			this->Explode();
		}

		if(this->placingStarted && input->is_action_just_released("place_nail") && this->remainingNails > 0)
		{
			this->remainingNails -= 1;
			godot::Godot::print("Nails reminding: {0}", this->remainingNails);
			Node* instance = nail->instance();
			Node2D* node = static_cast<Node2D*>(instance);
			node->set_z_index(++PlayerController::zOrder);
			node->set_position(mousePosition);
			add_child(node);
		}
	}

	void PlayerController::Explode()
	{
		godot::Godot::print("Explosion!");
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

	void PlayerController::CheckWinCondition()
	{
		checkWin = true;

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
			Godot::print("win");
		else
			Godot::print("raptot zjebałeś");
	}
}
