extends Node


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	get_node("../").connect("game_over", self, "play_animation")
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
func play_animation(value):
	if(value):
		get_node("Win").play("TitleAnimation")
		pass
	else:
		get_node("Lose").play("TitleAnimation")
		pass
	pass
