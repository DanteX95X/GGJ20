#ifndef PLAY_BUTTON_H
#define PLAY_BUTTON_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class PlayButton : public godot::Node2D
	{
		GODOT_CLASS(PlayButton, godot::Node2D)

	public:
		static void _register_methods();

		PlayButton();
		~PlayButton();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		void ButtonPressed();

		String nextLevelPath{};
		bool didPlayPhysics = false;
	};
}

#endif // PLAY_BUTTON_H
