#pragma once

#include "UIElement.h"

class UIText
{
public:
	UIText();
	UIText(int posX, int posY, std::string text);
	UIText(int posX, int posY, std::string text, std::string srcFont, int fontSize);
	UIText(int posX, int posY, std::string srcFont, int fontSize);

	void setFont(std::string srcFont);

	void setText(std::string str);
	void setText(int str);

	void setColor(sf::Color color);

	void setPosition(int posX, int posY);

	void setFontSize(int fontSize);

	void Draw(sf::RenderWindow& window) const;

private:

	sf::Font font;
	sf::Text text;
};

