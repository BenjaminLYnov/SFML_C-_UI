#include "UIElement.h"

UIElement::UIElement()
{

}

void UIElement::InitResources(int posX, int posY, int width, int height)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
}

void UIElement::setColor(sf::Color color)
{
}

void UIElement::setPosition(int posX, int posY)
{
}

void UIElement::Update(float dTime)
{
}

void UIElement::UpdateRect(int width, int height)
{
	this->width = width;
	this->height = height;
}

void UIElement::Draw(sf::RenderWindow& window) const
{
}
