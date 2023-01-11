#pragma once

#include "UIImage.h"

class ProgressBar
{
public:
    ProgressBar();
    ~ProgressBar();

    UIImage *getBar();
    void setPosition(int posX, int posY);
    void setColor(sf::Color color);

    void setProgressBarPourcentage(float pourcentage);

private:
    UIImage* bar;
};

