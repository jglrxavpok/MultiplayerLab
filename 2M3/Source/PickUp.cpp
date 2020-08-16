#include <PickUp.h>

PickUp::PickUp() :
	Entity(sf::Vector2f(0, 0), sf::RectangleShape(sf::Vector2f(0, 0))),
	mType(PickUpType::HealthPack)
{
}

PickUp::PickUp(PickUpType type, sf::Vector2f pos) :
	Entity(pos, sf::RectangleShape(sf::Vector2f(15, 15))),
	mType(type)
{
}

PickUp::PickUpType PickUp::getPickUpType()
{
	return mType;
}

void PickUp::onCollision(Entity* other)
{
	switch (other->getType())
	{
	/*case Type::CarType:
	{
		Car* otherCar = dynamic_cast<Car*>(other);

		switch (mType)
		{
		case PickUpType::HealthPack:
		{
			otherCar->repair(5);
			break;
		}
		case PickUpType::MissilesAmmo:
		{
			otherCar->addMissileAmmo(5);
			break;
		}
		default:
			break;
		}

		remove();
		break;
	}*/
	default:
		break;
	}
}