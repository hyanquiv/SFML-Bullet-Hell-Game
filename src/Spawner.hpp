#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include "Environment.hpp"
#include "Mod.hpp"

#include <memory>
#include <random>

static int irand(int min, int max) {
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> dis{ min, max };

	return dis(gen);
}

class Spawner {
public:
	Spawner(float x, Environment* env);
	Spawner(float x, Environment* env, int firetime, int postmovetime, sf::Color fill, sf::Color postmovefill, sf::Color warningfirefill, bool modded, Mod* parent, std::string name);
	~Spawner() {}

	void spawnerUpdate();
	void update();

	sf::RectangleShape render(sf::RenderWindow& window);
	bool customRender(sf::RenderWindow& window);

	int FIRE_TIME;
	int POST_MOVE_TIME;

	bool modded;
	Mod* parent;
	std::string m_name;

	sol::table instanceVars;

	bool getMoving();
	void setMoving(bool m);

	bool postmove = false;

	sf::Vector2f& getPosition();
	void setPosition(sf::Vector2f p);

protected:
	bool m_moving = false;
	int m_newX;
	int m_counter = 0;
	sf::Vector2f m_position;
	Environment* m_env;
	void spawnEnemy();

	int m_postMoveCounter = 0;
	sf::Color m_fill;
	sf::Color defaultFill;
	sf::Color postMoveFill;
	sf::Color warningMoveFill;
};

#endif /* SPAWNER_HPP */