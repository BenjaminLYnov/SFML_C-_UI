#include "GameData.h"

#include <iostream>
#include <algorithm>

void GameEvent::PrintEvent()
{
    std::cout << "At time [" << time << "] On Player " << player << " --> ";
    if (scoreDelta != 0)
        std::cout << "Score delta [" << scoreDelta << "] ";

    if (healthDelta != 0)
        std::cout << "Health delta [" << healthDelta << "] ";

    if (manaDelta != 0)
        std::cout << "Mana delta [" << manaDelta << "] ";

    std::cout << std::endl;
}

GameData::~GameData()
{
    delete playersHealthBar;
    delete playersText;
    delete PlayersManaBar;
}

void GameData::Init()
{
    int nbEvents = 100;

    m_vEvents.clear();

    for (int i = 0; i < nbPlayers; i++)
    {
        players[i].playerID = i;
        players[i].fHealth = players[i].fMaxHealth;
        players[i].fMana = players[i].fMaxMana;
    }


    for (int i = 0; i < nbEvents; i++)
    {
        GameEvent sEvent;
        sEvent.time = float(rand() % 100);
        sEvent.player = rand() % 2;
        sEvent.healthDelta = (rand() % 10) - 8;
        sEvent.manaDelta = (rand() % 10) - 8;
        sEvent.scoreDelta = (rand() % 10) - 5;

        m_vEvents.push_back(sEvent);
    }

    float timeEvents = 0;

    InitHealthBar();

    PlayersManaBar = new ManaBar[nbPlayers];
    PlayersManaBar[0].SetManaBarPosition(600, 50);
    PlayersManaBar[1].SetManaBarPosition(600, 100);

    playersText = new UIText[nbPlayers];

    playersText[0].setText("Player 1");
    playersText[1].setText("Player 2");

    playersText[0].setPosition(50, 50);
    playersText[1].setPosition(50, 110);
}

void GameData::InitHealthBar()
{
    playersHealthBar = new HealthBar[nbPlayers];

    playersHealthBar[0].SetHealthBarPosition(200, 50);
    playersHealthBar[1].SetHealthBarPosition(200, 100);

}

void ClampVal(float& val, float min, float max)
{

}

void PlayerInfos::ApplyEvent(const GameEvent& _event)
{
    fHealth += _event.healthDelta;
    fMana += _event.manaDelta;
    fScore += _event.scoreDelta;

    ClampVal(fHealth, 0, fMaxHealth);
    ClampVal(fMana, 0, fMaxMana);

}

void PlayerInfos::PrintData()
{
    std::cout << "Player " << playerID << "[Health] : " << fHealth << "[Mana] : " << fMana << " [Score] : " << fScore << std::endl;
}

void GameData::Update()
{
    sf::Time elapsed = m_clock.restart();

    m_timeEvents += elapsed.asSeconds();

    for (GameEvent& sEvent : m_vEvents)
    {
        if (!sEvent.triggered)
        {
            if (sEvent.time < m_timeEvents)
            {
                players[sEvent.player].ApplyEvent(sEvent);
                players[sEvent.player].PrintData();

                sEvent.triggered = true;
                playersHealthBar[sEvent.player].UpdateProgressBar(players[sEvent.player].fHealth);

            }
        }
    }


}

void GameData::DrawHealthBars(sf::RenderWindow& window) const
{
    for (int i = 0; i < nbPlayers; i++)
    {
        playersHealthBar[i].Draw(window);
    }
}

void GameData::Draw(sf::RenderWindow& window) const
{
    for (int i = 0; i < nbPlayers; i++)
    {
        playersText[i].Draw(window);
        PlayersManaBar[i].Draw(window);
    }

    DrawHealthBars(window);
}
