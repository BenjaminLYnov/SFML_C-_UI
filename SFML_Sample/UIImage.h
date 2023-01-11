#pragma once

#include "UIElement.h"

class UIImage: public UIElement
{
public:
	UIImage(std::string srcImg, int posX, int posY, int width, int height);

	void setImage(std::string srcImg, int posX, int posY, int width, int height);
	
	void setColor(sf::Color color);

	void setPosition(int posX, int posY);

	void Update(float dTime);

	void UpdateRect(int width, int height);


	void UpdateRectByPourcentage(float widthP, float heightP);
	void UpdateRectByPourcentage(float widthP);

	void Draw(sf::RenderWindow& window) const;

private:
	sf::Texture texture;
	sf::Sprite sprite;

	int width, height;
};

