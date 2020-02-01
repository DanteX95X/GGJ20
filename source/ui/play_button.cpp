#include "play_button.h"
#include <SceneTree.hpp>

namespace godot
{
	void PlayButton::_register_methods()
	{
		godot::register_method("_ready", &PlayButton::_ready);
		godot::register_method("_process", &PlayButton::_process);

		godot::register_method("ButtonPressed", &PlayButton::ButtonPressed);

		godot::register_signal<PlayButton>("play_physics");
		godot::register_property<PlayButton, String>("NextLevelPath", &PlayButton::nextLevelPath, "Pls, ustaw mnie!");
	}

	PlayButton::PlayButton()
	{
	}

	PlayButton::~PlayButton()
	{
	}

	void PlayButton::_init()
	{
	}

	void PlayButton::_ready()
	{
		this->connect("pressed", this, "ButtonPressed");
	}

	void PlayButton::_process(float delta)
	{
	}

	void PlayButton::ButtonPressed()
	{
		if(!didPlayPhysics)
		{
			emit_signal("play_physics");
			didPlayPhysics = true;
		}
		else
		{
			Godot::print("changing scene to next level");
			get_tree()->change_scene(nextLevelPath);

		}
	}
}
