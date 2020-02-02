extends Label


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
export var showSignal = ""
export var hideSignal = ""

# Called when the node enters the scene tree for the first time.
func _ready():
	if(showSignal != ""):
		get_node("../..").connect(showSignal, self, "show")
		pass
	if(hideSignal != ""):
		get_node("../..").connect(hideSignal, self, "hide")
		pass
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func show():
	self.visible = true
	pass
	
func hide(value = true):
	self.visible = false
	pass
