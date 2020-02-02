extends Label


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
export(bool) var expectedValue

# Called when the node enters the scene tree for the first time.
func _ready():
	get_node("../../").connect("game_over", self, "show_self")
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
func show_self(value):
	if(value == expectedValue):
		self.visible = true
		pass
	pass
