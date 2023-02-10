Render = Game.RenderSystem
Input = Game.InputSystem

FIELD_SIZE = 20
Snake = {{1, 1}, {1, 2}, {1, 3}}
Food = {random(1, FIELD_SIZE-1), random(1, FIELD_SIZE-1)}
-- TODO: добавить проверку находится ли еда в змейке
Direction = 's' -- w, a, s, d

Render:Prepare(FIELD_SIZE, FIELD_SIZE)
Input:OnKey('w', function() direction = 'w' end)
Input:OnKey('a', function() direction = 'a' end)
Input:OnKey('s', function() direction = 's' end)
Input:OnKey('d', function() direction = 'd' end)

function Update()
	Render:DrawRect('#', 0, 0, FIELD_SIZE, FIELD_SIZE)
	-- представьте что здесь есть код змейки
	for i = 1, #Snake do -- рисуем змею
		Render:DrawPoint('@', Snake[i][1], Snake[i][2])
	end
	Render:DrawPoint('&', Food[1], Food[2]) -- отрисовка еды
end
