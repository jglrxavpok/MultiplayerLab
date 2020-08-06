#pragma once
#include <SFML/Window/Keyboard.hpp>

#include <map>
#include <vector>

namespace PlayerAction
{
	enum Type
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		Fire,
		Count
	};
}

class KeyBinding
{
public:
	typedef PlayerAction::Type Action;


public:
	explicit				KeyBinding(int controlPreconfiguration);

	void					assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key		getAssignedKey(Action action) const;

	bool					checkAction(sf::Keyboard::Key key, Action& out) const;

private:
	std::map<sf::Keyboard::Key, Action>		mKeyMap;
};