#ifndef RELOAD_BUTTON_H
#define RELOAD_BUTTON_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Button.hpp>

namespace godot
{
	class ReloadButton : public godot::Button
	{
		GODOT_CLASS(ReloadButton, godot::Button)

	public:
		static void _register_methods();

		ReloadButton();
		~ReloadButton();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		void ReloadLevel();
	};
}

#endif // RELOAD_BUTTON_H
