#include "UIImage.h"


UIImage::UIImage(std::string srcImg, int posX, int posY, int width, int height)
{
	setImage(srcImg, posX, posY, width, height);

	this->width = width;
	this->height = height;
}

void UIImage::setImage(std::string srcImg, int posX, int posY, int width, int height)
{
	texture.loadFromFile(srcImg, sf::IntRect(0, 0, width, height));
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
}

void UIImage::setColor(sf::Color color)
{
	sprite.setColor(color); 
}

void UIImage::setPosition(int posX, int posY)
{
	sprite.setPosition(posX, posY);
}

void UIImage::Update(float dTime)
{
}

void UIImage::UpdateRect(int width, int height)
{
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));

	this->width = width;
	this->height = height;
}

void UIImage::UpdateRectByPourcentage(float widthP)
{
	float width = this->width * widthP / 100;
	sprite.setTextureRect(sf::IntRect(0, 0, width, this->height));
}

void UIImage::UpdateRectByPourcentage(float widthP, float heightP)
{
	float width = this->width * widthP / 100;
	float height = this->height * heightP / 100;
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}


void UIImage::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}
