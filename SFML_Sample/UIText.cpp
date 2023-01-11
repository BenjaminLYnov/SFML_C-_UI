#include "UIText.h"
#include <iostream>

// Contructs
UIText::UIText()
{
	setFont("Resources/Fonts/SuperMarioBros-ov7d.ttf");
	setText("Nouveau Text");
	setPosition(0, 0);
	setFontSize(16);
}

UIText::UIText(int posX, int posY, std::string text)
{
	setFont("Resources/Fonts/SuperMarioBros-ov7d.ttf");
	setText(text);
	setPosition(posX, posY);
	setFontSize(16);
}

UIText::UIText(int posX, int posY, std::string text, std::string srcFont, int fontSize)
{
	setFont(srcFont);
	setText(text);
	setPosition(posX, posY);
	setFontSize(fontSize);
}

UIText::UIText(int posX, int posY, std::string srcFont, int fontSize)
{
	setFont(srcFont);
	setText("Nouveau Text");
	setPosition(posX, posY);
	setFontSize(fontSize);
}

// Contructs

void UIText::setFont(std::string srcFont)
{
	font.loadFromFile(srcFont);
	text.setFont(font);
}

void UIText::setText(std::string str)
{
	text.setString(str);
}

void UIText::setText(int str)
{
	text.setString(std::to_string(str));
}

void UIText::setColor(sf::Color color)
{
	text.setFillColor(color);
}

void UIText::setPosition(int posX, int posY)
{
	text.setPosition(posX, posY);
}

void UIText::setFontSize(int fontSize)
{
	text.setCharacterSize(fontSize);
}

void UIText::Draw(sf::RenderWindow& window) const
{
	window.draw(text);
}
