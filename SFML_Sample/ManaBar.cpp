#include "ManaBar.h"
    
ManaBar::ManaBar()
{
    SetManaBarPosition(0, 0);
}

ManaBar::ManaBar(int posX, int posY)
{
    SetManaBarPosition(posX, posY);
}

void ManaBar::SetManaBarPosition(int posX, int posY)
{
    progressBar->getBar()->setPosition(posX, posY);
}

void ManaBar::UpdateProgressBar(float pourcentage)
{
    progressBar->setProgressBarPourcentage(pourcentage);

    if (pourcentage >= 60)
    {
        progressBar->setColor(sf::Color(1, 47, 253)); 
    }
    else if (pourcentage >= 30)
    {
        progressBar->setColor(sf::Color(1, 131, 253));
    }
    else {
        progressBar->setColor(sf::Color(1, 253, 249));
    }
}

void ManaBar::Draw(sf::RenderWindow& window) const
{
    progressBar->getBar()->Draw(window);
}
