Render = Game.RenderSystem
Input = Game.InputSystem

FIELD_SIZE = 20
Snake = {{1, 1}, {1, 2}, {1, 3}}
Food = {random(1, FIELD_SIZE-1), random(1, FIELD_SIZE-1)}
Direction = 's' # w, a, s, d

Render:Prepare(FIELD_SIZE, FIELD_SIZE)

function Update()
	Render:DrawRect('#', 0, 0, FIELD_SIZE, FIELD_SIZE)


end
