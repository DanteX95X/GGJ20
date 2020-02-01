#include "play_button.h"

namespace godot
{
	void PlayButton::_register_methods()
	{
		godot::register_method("_ready", &PlayButton::_ready);
		godot::register_method("_process", &PlayButton::_process);

		godot::register_method("PlayPhysics", &PlayButton::PlayPhysics);

		godot::register_signal<PlayButton>("play_physics");
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
		this->connect("pressed", this, "PlayPhysics");
	}

	void PlayButton::_process(float delta)
	{
	}

	void PlayButton::PlayPhysics()
	{
		emit_signal("play_physics");
	}
}
