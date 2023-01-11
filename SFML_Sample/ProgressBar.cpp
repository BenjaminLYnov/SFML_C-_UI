#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
    bar = new UIImage("Resources/Images/enemy_health_bar_000.png", 0, 0, 256, 64);
}

ProgressBar::~ProgressBar()
{
    delete bar;
}

UIImage* ProgressBar::getBar()
{
    return bar;
}

void ProgressBar::setPosition(posX, posY) {
    bar->setPosition(posX, posY);
}

void ProgressBar::setColor(sf::Color color)
{
    bar->setColor(color);
}

void ProgressBar::setProgressBarPourcentage(float pourcentage)
{
    bar->UpdateRectByPourcentage(pourcentage);
}
