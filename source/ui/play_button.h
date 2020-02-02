#ifndef PLAY_BUTTON_H
#define PLAY_BUTTON_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <TextureButton.hpp>
#include <Texture.hpp>

namespace godot
{
	class PlayButton : public godot::TextureButton
	{
		GODOT_CLASS(PlayButton, godot::TextureButton)

	public:
		static void _register_methods();

		PlayButton();
		~PlayButton();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		void ButtonPressed();
		void OnGameOver(bool win);
		void OnLevelReady();

		String nextLevelPath{};
		bool didPlayPhysics = false;

		Ref<Texture> normalTexture{};
		Ref<Texture> hoverTexture{};
		Ref<Texture> pressedTexture{};
	};
}

#endif // PLAY_BUTTON_H
