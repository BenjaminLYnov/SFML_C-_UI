#pragma once

#include <SFML/Graphics.hpp>

class UIElement
{
public:
	 UIElement();

	void InitResources(int posX, int posY, int width, int height);

	virtual void setColor(sf::Color color);
	virtual void setPosition(int posX, int posY);
	virtual void Update(float dTime);
	virtual void UpdateRect(int width, int height);
	virtual void Draw(sf::RenderWindow& window) const;

protected:

	int posX, posY, width, height;


};

