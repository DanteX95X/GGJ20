#include "play_button.h"
#include <SceneTree.hpp>

namespace godot
{
	void PlayButton::_register_methods()
	{
		godot::register_method("_ready", &PlayButton::_ready);
		godot::register_method("_process", &PlayButton::_process);

		godot::register_method("ButtonPressed", &PlayButton::ButtonPressed);
		godot::register_method("OnGameOver", &PlayButton::OnGameOver);

		godot::register_signal<PlayButton>("play_physics", Dictionary());
		godot::register_property<PlayButton, String>("NextLevelPath", &PlayButton::nextLevelPath, "Pls, ustaw mnie!");
		godot::register_property<PlayButton, Ref<Texture>>("HoverTexture", &PlayButton::hoverTexture, nullptr);
		godot::register_property<PlayButton, Ref<Texture>>("NormalTexture", &PlayButton::normalTexture, nullptr);
		godot::register_property<PlayButton, Ref<Texture>>("PressedTexture", &PlayButton::pressedTexture, nullptr);
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
			set_disabled(true);
		}
		else
		{
			Godot::print("changing scene to next level");
			get_tree()->change_scene(nextLevelPath);

		}
	}

	void PlayButton::OnGameOver(bool win)
	{
		if(win)
		{
			set_disabled(false);
			this->set_hover_texture(hoverTexture);
			this->set_normal_texture(normalTexture);
			this->set_pressed_texture(pressedTexture);
		}
	}
}
