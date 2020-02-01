#include "reload_button.h"
#include <SceneTree.hpp>

namespace godot
{
	void ReloadButton::_register_methods()
	{
		godot::register_method("_ready", &ReloadButton::_ready);
		godot::register_method("_process", &ReloadButton::_process);

		godot::register_method("ReloadLevel", &ReloadButton::ReloadLevel);
	}

	ReloadButton::ReloadButton()
	{
	}

	ReloadButton::~ReloadButton()
	{
	}

	void ReloadButton::_init()
	{
	}

	void ReloadButton::_ready()
	{
		this->connect("pressed", this, "ReloadLevel");
	}

	void ReloadButton::_process(float delta)
	{
	}

	void ReloadButton::ReloadLevel()
	{
		get_tree()->reload_current_scene();
	}
}
