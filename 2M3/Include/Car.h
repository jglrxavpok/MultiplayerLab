#pragma once
#define _USE_MATH_DEFINES
#include <Entity.h>
#include <math.h>
#include <KeyBinding.h>
#include <Projectile.h>
#include <Particles.h>

class Car : public Entity
{
public:
	Car();
	Car(int hp, sf::Vector2f pos, sf::RectangleShape rect, KeyBinding keys);

	void update(sf::Time dt, std::vector<Entity*>& newEntities) override;
	void getInput(sf::Time dt, std::vector<Entity*>& newEntities);

	void draw(sf::RenderTarget& target) override;

	void damage(int points);
	void repair(int points);

	void onCollision(Entity* other) override;

private:
	int mHP;
	int mHpMax;

	KeyBinding mKeyBindings;

	sf::Vector2f mCarDirection;

	const float mCarMaxSpeed = 1000;
	const float mCarBackwardsMaxSpeed = mCarMaxSpeed / 3;
	const float mCarAcceleration = 200;
	const float mTurnRadius = 12;
	const float mDriftTheshold = mCarMaxSpeed - 200;
	const float mDriftAngle = M_PI / 3;
	const float mDrag = 0.001;

	bool mForward;
	bool mDrifting;
	float mPrevDriftingSign;

	sf::VertexArray mTires;
	Particles mDust;

	sf::Time mShootDelay;
	sf::Time mCurrentShootDelay;

};