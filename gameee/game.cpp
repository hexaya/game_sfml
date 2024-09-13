#include "game.h"

void Game::openMenu()
{

    if (!this->font.loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Fonts/slkscr.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
    }


    if (!this->menuBackgroundTexture.loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Textures/space1.jpg"))
    {
        std::cerr << "Failed to load menu background" << std::endl;
    }
    this->menuBackground.setTexture(this->menuBackgroundTexture);


    this->playText.setFont(this->font);
    this->playText.setString("Play");
    this->playText.setCharacterSize(50);
    this->playText.setFillColor(sf::Color::White);
    this->playText.setPosition(this->window->getSize().x / 2.f - this->playText.getGlobalBounds().width / 2.f, 400.f);


    this->quitText.setFont(this->font);
    this->quitText.setString("Quit");
    this->quitText.setCharacterSize(50);
    this->quitText.setFillColor(sf::Color::White);
    this->quitText.setPosition(this->window->getSize().x / 2.f - this->quitText.getGlobalBounds().width / 2.f, 500.f);

    this->difficultyText.setFont(this->font);
    this->difficultyText.setString("Difficulty");
    this->difficultyText.setCharacterSize(50);
    this->difficultyText.setFillColor(sf::Color::White);
    this->difficultyText.setPosition(this->window->getSize().x / 2.f - this->difficultyText.getGlobalBounds().width / 2.f, 600.f);


    this->instructionsText.setFont(this->font);
    this->instructionsText.setCharacterSize(25);
    this->instructionsText.setFillColor(sf::Color::White);
    this->instructionsText.setString("Instructions:\n\n"
                                     "Move: W, A, S, D\n"
                                     "Shoot: Space\n"
                                     "Die: When your HP reaches 0\n"
                                     "Win: Score 200 points\n");
    this->instructionsText.setPosition(50.f, 50.f);

    this->selectedMenuItem = -1;
    this->inMenu = true;
}


void Game::openWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 1200), "Cosmic Defence", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::openTextures()
{
    this->textures["LASER"] = new sf::Texture();
    this->textures["LASER"] ->loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Textures/laser.png");

}

void Game::openText()
{
    if(!this->font.loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Fonts/slkscr.ttf"));

    this->pointText.setPosition(1450, 25.f);
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(20);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("points:");

    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(60);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setString("GAME OVER");
    this->gameOverText.setPosition(
        this->window->getSize().x/2.f - this->gameOverText.getGlobalBounds().width/2,
        this->window->getSize().y/2.f - this->gameOverText.getGlobalBounds().height/2
        );

    this->youWinText.setFont(this->font);
    this->youWinText.setCharacterSize(60);
    this->youWinText.setFillColor(sf::Color::Blue);
    this->youWinText.setString("YOU WIN");
    this->youWinText.setPosition(
        this->window->getSize().x/2.f - this->youWinText.getGlobalBounds().width/2,
        this->window->getSize().y/2.f - this->youWinText.getGlobalBounds().height/2
        );

    this->playerHPbar.setSize(sf::Vector2f(300.f, 25.f));
    this->playerHPbar.setFillColor(sf::Color::Red);
    this->playerHPbar.setPosition(sf::Vector2f(20.f, 20.f));

    this->playerHPbarMax = this->playerHPbar;
    this->playerHPbarMax.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::openBackground()
{
    this->Background.loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Textures/space1.jpg");
    this->worldBackground;

    this->worldBackground.setTexture(this->Background);
}

void Game::openSystems()
{
    this->difficulty = EASY;

    this->points = 0;
}


void Game::openPlayer()
{
    this->playerShip = new PlayerShip();

    if (this->difficulty == HARD)
    {
        this->playerShip->setHp(this->playerShip->getHpMax() / 2);
    }



}

void Game::openEnemies()
{
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
}

Game::Game() {

    this->openWindow();
    this->openTextures();
    this->openPlayer();
    this->openEnemies();
    this->openText();
    this->openBackground();
    this->openSystems();
    this->openMenu();

}
Game::~Game() {

    delete this->window;
    delete this->playerShip;

    for(auto &i : this->textures)
    {
        delete i.second;
    }

    for (auto *i : this->lasers)
    {
        delete i;
    }

    for (auto *i : this->enemyShips)
    {
        delete i;
    }
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updatePollEvents();

        if (this->inMenu)
        {

            this->updateMenu();
            this->renderMenu();
        }
        else
        {

            if (this->playerShip->getHp() > 0)
                this->update();

            this->render();
        }
    }
}


void Game::updateMenu()
{

    sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);


    if (this->playText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        this->playText.setFillColor(sf::Color::Green);
        this->quitText.setFillColor(sf::Color::White);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->inMenu = false;
        }
    }

    else if (this->quitText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        this->quitText.setFillColor(sf::Color::Green);
        this->playText.setFillColor(sf::Color::White);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->window->close();
        }
    }
    else
    {

        this->playText.setFillColor(sf::Color::White);
        this->quitText.setFillColor(sf::Color::White);
    }




    if (this->difficultyText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        this->difficultyText.setFillColor(sf::Color::Green);
        this->playText.setFillColor(sf::Color::White);
        this->quitText.setFillColor(sf::Color::White);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (this->difficulty == EASY)
            {
                this->difficulty = HARD;
                this->difficultyText.setString("Difficulty: Hard");
            }
            else
            {
                this->difficulty = EASY;
                this->difficultyText.setString("Difficulty: Easy");
            }

            this->difficultyText.setPosition(this->window->getSize().x / 2.f - this->difficultyText.getGlobalBounds().width / 2.f, 600.f);
        }
    }
    else
    {
        this->difficultyText.setFillColor(sf::Color::White);
    }

}



void Game::updatePollEvents()
{
    sf::Event eve;
    while(this->window->pollEvent(eve))
    {
        if(eve.Event::type == sf::Event::Closed || (eve.Event::KeyPressed && eve.Event::key.code == sf::Keyboard::Escape))
            this->window->close();

    }
}

void Game::updateInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->playerShip->move(-1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->playerShip->move(1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->playerShip->move(0.f, 1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->playerShip->move(0.f, -1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->playerShip->attackCDup())
    {

        this->lasers.push_back(new Laser(this->textures["LASER"], this->playerShip->getPos().x + this->playerShip->getBounds().width/3.f, this->playerShip->getPos().y, 0.f, -1.f, 5.f));
    }

}

void Game::updateText()
{
    std::stringstream ss;

    ss<< "Points: " << this->points;

    this->pointText.setString(ss.str());


    float hpPercent = static_cast<float>(this->playerShip->getHp())/this->playerShip->getHpMax();
    this->playerHPbar.setSize(sf::Vector2f(300.f*hpPercent,this->playerHPbar.getSize().y));


}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
    //left
    if(this->playerShip->getBounds().left < 0.f){
        this->playerShip->setPosition(0.f, this->playerShip->getBounds().top);
    }
    //right
    else if(this->playerShip->getBounds().left + this->playerShip->getBounds().width >= this->window->getSize().x)
    {
        this->playerShip->setPosition(this->window->getSize().x - this->playerShip->getBounds().width, this->playerShip->getBounds().top);
    }

    //top
    if(this->playerShip->getBounds().top < 0.f){
        this->playerShip->setPosition(this->playerShip->getBounds().left, 0.f);
    }



    //bottom
    else if(this->playerShip->getBounds().top + this->playerShip->getBounds().height >= this->window->getSize().y){
        this->playerShip->setPosition(this->playerShip->getBounds().left, this->window->getSize().y - this->playerShip->getBounds().height);
    }

}

void Game::updateLaser()
{
    unsigned counter = 0;
    for(auto *laser : this->lasers)
    {
        laser->update();

        if(laser->getBounds().top + laser->getBounds().height < 0.f)
        {   delete this->lasers.at(counter);
            this->lasers.erase(this->lasers.begin() + counter);

        }
        ++counter;
    }

}


void Game::updateEnemies()
{
    if (this->difficulty == HARD)
    {
        this->enemySpawnTimerMax = 3.f; // 3x faster spawn rate
    }
    else
    {
        this->enemySpawnTimerMax = 10.f; // Normal spawn rate
    }

    this->enemySpawnTimer += 0.1f;
    if(this->enemySpawnTimer >= this->enemySpawnTimerMax){

        this->enemyShips.push_back(new EnemyShip(rand()% this->window->getSize().x-20.f, - 100.f));
        this->enemySpawnTimer = 0.f;
    }

    unsigned counter = 0;
    for(auto *enemyShip : this->enemyShips)
    {
        enemyShip->update();

        if(enemyShip->getBounds().top  > this->window->getSize().y)
        {   delete this->enemyShips.at(counter);
            this->enemyShips.erase(this->enemyShips.begin() + counter);

        }

        else if (enemyShip->getBounds().intersects(this->playerShip->getBounds())){
            this->playerShip->loseHp(this->enemyShips.at(counter)->getDamage());

            delete this->enemyShips.at(counter);
            this->enemyShips.erase(this->enemyShips.begin() + counter);


        }
        else if (enemyShip->getBounds().intersects(this->playerShip->getBounds()))
        {
            if (this->difficulty == HARD)
            {
                this->playerShip->loseHp(this->enemyShips.at(counter)->getDamage() * 3);  // 3x enemy damage
            }
            else
            {
                this->playerShip->loseHp(this->enemyShips.at(counter)->getDamage());
            }

            delete this->enemyShips.at(counter);
            this->enemyShips.erase(this->enemyShips.begin() + counter);
        }
        ++counter;
    }


}



void Game::updateEnemyLaser()
{


    for(int i = 0; i < this->enemyShips.size(); ++i)
    {
        bool enemyShip_removed = false;

        for(size_t j=0; j<this->lasers.size()&& enemyShip_removed==false; j++)
        {

            if(this->enemyShips[i]->getBounds().intersects(this->lasers[j]->getBounds())){

                this->points += this->enemyShips[i]->getPoints();

                delete this->enemyShips[i];
                this->enemyShips.erase(this->enemyShips.begin()+i);

                delete this->lasers[j];
                this->lasers.erase(this->lasers.begin()+j);

                enemyShip_removed=true;
            }
        }
    }
}

void Game::update()
{
    this->updateInput();

    if (this->playerShip->getHp() > 0)
    {
        this->playerShip->update();
        this->updateCollision();
        this->updateLaser();
        this->updateEnemies();
        this->updateEnemyLaser();
        this->updateText();

        if (this->points >= 200)
        {
            this->window->draw(this->youWinText);
            this->window->display();
            sf::sleep(sf::seconds(2));
            this->inMenu = true;
        }
    }
    else
    {
        this->window->draw(this->gameOverText);
        this->window->display();
        sf::sleep(sf::seconds(2));
        this->inMenu = true;
    }

    this->updateWorld();
}


void Game::renderWorld()
{
    this->window->draw(this->worldBackground);
}

void Game::renderMenu()
{
    this->window->clear();


    this->window->draw(this->menuBackground);


    this->window->draw(this->playText);
    this->window->draw(this->quitText);

    this->window->draw(this->difficultyText);

    this->window->draw(this->instructionsText);

    this->window->display();
}



void Game::render()
{
    this->window->clear();

    this->renderWorld();

    this->playerShip->render(*this->window);

    for(auto *laser : this->lasers)
    {
        laser->render(this->window);
    }

    for(auto *enemyShip : this->enemyShips)
    {
        enemyShip->render(this->window);
    }


    this->renderText();

    if(this->playerShip->getHp()<=0)
        this->window->draw(this->gameOverText);

    if(this->points >=200)
        this->window->draw(this->youWinText);

    this->window->display();

}


void Game::renderText()
{
    this->window->draw(this->pointText);
    this->window->draw(this->playerHPbarMax);
    this->window->draw(this->playerHPbar);


}
