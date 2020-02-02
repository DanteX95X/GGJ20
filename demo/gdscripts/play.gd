extends Button


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var canPlay = false
var time = 0
export var path = "res://scenes/"

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(canPlay):
		time = time + delta
		if(time > 1):
			get_tree().change_scene(path)
			pass
		pass
	pass


func _on_Button_pressed():
	#get_tree().change_scene("res://scenes/PlayerCtrl.tscn")
	var animator = get_node("../../HammerAnimation")
	animator.get_node("Hammer").global_position = get_global_mouse_position() + Vector2(100,-4)
	animator.play("HammerAnimation")
	canPlay = true
	pass # Replace with function body.


func _on_TextureButton_pressed():
	pass # Replace with function body.
