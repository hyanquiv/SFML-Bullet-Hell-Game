WaveSpawner = {
	fireTime = 400,
	fill = Color.new(0, 0, 255),
	warningFireFill = Color.new(0, 206, 209)
}

WaveSpawner.SpawnerInstanceVars = {
	ec = 0
}

function WaveSpawner.SpawnerInstanceVars:new(o)
	o = o or {}
	setmetatable(0, self)
	self.__index = self
	self.ec = 0
	return o
end

function WaveSpawner.spawnEnemies(spawner)
	return {
		amount = 1,
		enemies = {
			Enemy.new(spawner.position.x + 3, spawner.position.y + 20, 0.0, 2.0, 300, Color.new(0, 0, 0))
		}		
	}
end

function WaveSpawner.spawnerUpdate(spawner, environment)
	if not spawner.moving then
		return
	end
	if spawner.spawnerInstanceVars.ec > 10 then
		e = Enemy.new(spawner.position.x + 3, spawner.position.y + 20, 0.0, 2.0, 300, Color.new(0, 0, 0))
		environment:addEnemy(e, "WaveSpawner")
		spawner.spawnerInstanceVars.ec = 0
	end
	spawner.spawnerInstanceVars.ec = spawner.spawnerInstanceVars.ec + 1
end