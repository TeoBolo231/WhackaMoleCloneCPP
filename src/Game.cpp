
#include "Game.h"
#include <iostream>
#include "iomanip"
#include "string"

/*============================================================================*/

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

/*============================================================================*/

// Class Destructor
Game::~Game()
{

}

/*============================================================================*/

// Game Initializer
bool Game::init()
{
  start_menu = true;
  is_running = false;
  play_again_menu = false;
  end_screen = false;

  /*--------------------------------------------------------------------------*/

  // Game Title
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  title_text.setString("Whack-a-Mole");
  title_text.setFont(font_game);
  title_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  title_text.setCharacterSize(50);
  title_text.setFillColor(sf::Color(0, 0, 0, 255));
  title_text.setPosition
    (
      window.getSize().x/2 - title_text.getGlobalBounds().width/2, 0
    );

  /*--------------------------------------------------------------------------*/

  //Start Menu

  // BG
  if (!background_texture_menu.loadFromFile("Data/Images/mole_bg.png"))
  {
    std::cout << "Background texture not loaded\n";
    return false;
  }
  background_menu.setTexture(background_texture_menu);
  background_menu.setScale
    (
      window.getSize().x / background_menu.getGlobalBounds().width,
      window.getSize().y / background_menu.getGlobalBounds().height
    );
  background_menu.setPosition(0, 0);

  // Rules
  if (!font_menu.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  rules_text.setString("                                 Welcome to Whack-a-Mole!\n" // Is this cheating? 🤔
                             "Try to catch as many animals as you can within the time limit.\n"
                             "                                Beware, don't touch the ball!\n\n"
                             "              Elephant = 1pt\n"
                             "               Buffalo = 2pt\n"
                             "                   Owl = 3pt\n"
                             "                   Ball = -6pt\n");
  rules_text.setFont(font_menu);
  rules_text.setCharacterSize(30);
  rules_text.setFillColor(sf::Color(255, 255, 0, 255));
  rules_text.setPosition
    (
      window.getSize().x/2 - rules_text.getGlobalBounds().width/2,
      window.getSize().y - window.getSize().y/2 - rules_text.getGlobalBounds().height/2 - window.getSize().y/10
    );

  // Play Option
  if (!font_menu.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  play_option.setString(">Play<");
  play_option.setStyle(sf::Text::Italic | sf::Text::Bold);
  play_option.setFont(font_menu);
  play_option.setCharacterSize(30);
  play_option.setFillColor(sf::Color(255, 255, 0, 255));
  play_option.setPosition
    (
      window.getSize().x/2 - play_option.getGlobalBounds().width/2 - window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - play_option.getGlobalBounds().height/2
    );

  // Quit Option
  if (!font_menu.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  quit_option.setString("Quit");
  quit_option.setFont(font_menu);
  quit_option.setCharacterSize(30);
  quit_option.setFillColor(sf::Color(255, 255, 0, 255));
  quit_option.setPosition
    (
      window.getSize().x - window.getSize().x/3 - quit_option.getGlobalBounds().width/2 - window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - quit_option.getGlobalBounds().height/2
    );

  /*--------------------------------------------------------------------------*/

  // Esc Menu

  // BG
  if (!background_texture_esc_menu.loadFromFile("Data/Images/menu_bg.png"))
  {
    std::cout << "Background texture not loaded\n";
    return false;
  }
  background_esc_menu.setTexture(background_texture_esc_menu);
  background_esc_menu.setScale
    (
      window.getSize().x / background_esc_menu.getGlobalBounds().width,
      window.getSize().y / background_esc_menu.getGlobalBounds().height
    );
  background_esc_menu.setPosition(0, 0);

  // Pause
  if (!font_menu.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  pause_text.setString("PAUSE");
  pause_text.setFont(font_menu);
  pause_text.setCharacterSize(80);
  pause_text.setFillColor(sf::Color(0, 0, 0, 255));
  pause_text.setPosition
    (
      window.getSize().x/2 - pause_text.getGlobalBounds().width/2,
      window.getSize().y/3 - pause_text.getGlobalBounds().height/2 - window.getSize().y/10
    );

  // Restart Option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  restart_text.setString(">Restart<");
  restart_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  restart_text.setFont(font_game);
  restart_text.setCharacterSize(30);
  restart_text.setFillColor(sf::Color(0, 0, 0, 255));
  restart_text.setPosition
    (
      window.getSize().x/3 - restart_text.getGlobalBounds().width/2 + window.getSize().x/20,
      window.getSize().y - window.getSize().y/2 - restart_text.getGlobalBounds().height/2
    );

  // Quit option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  quit_escape.setString("Quit");
  quit_escape.setFont(font_game);
  quit_escape.setCharacterSize(30);
  quit_escape.setFillColor(sf::Color(0, 0, 0, 255));
  quit_escape.setPosition
    (
      window.getSize().x - window.getSize().x/3 - quit_escape.getGlobalBounds().width/2 - window.getSize().x/20,
      window.getSize().y/2 - quit_escape.getGlobalBounds().height/2
    );

  /*--------------------------------------------------------------------------*/

  // Win Screen

  //BG
  if (!end_screen_bg_texture.loadFromFile("Data/Images/background.png"))
  {
    std::cout << "Background texture not loaded\n";
    return false;
  }
  end_screen_bg.setTexture(end_screen_bg_texture);
  end_screen_bg.setScale
    (
      window.getSize().x / end_screen_bg.getGlobalBounds().width,
      window.getSize().y / end_screen_bg.getGlobalBounds().height
    );
  end_screen_bg.setPosition(0, 0);

  // Result
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  end_screen_text.setString("Well done, you earned: " + std::to_string(score) +
                                  " points!\n"
                                  "Can you do better?");
  end_screen_text.setFont(font_game);
  end_screen_text.setCharacterSize(30);
  end_screen_text.setFillColor(sf::Color(0, 0, 0, 255));
  end_screen_text.setPosition
    (
      window.getSize().x/2 - end_screen_text.getGlobalBounds().width/2,
      window.getSize().y - window.getSize().y - end_screen_text.getGlobalBounds().height/2 + 2 * window.getSize().y/10

    );

  // Play again option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  play_again_text.setString(">Play again<");
  play_again_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  play_again_text.setFont(font_game);
  play_again_text.setCharacterSize(30);
  play_again_text.setFillColor(sf::Color(0, 0, 0, 255));
  play_again_text.setPosition
    (
      window.getSize().x/3 - play_again_text.getGlobalBounds().width/2 + window.getSize().x/20,
      window.getSize().y - window.getSize().y/2 - play_again_text.getGlobalBounds().height/2
    );

  // Quit option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  quit_text.setString("Quit");
  quit_text.setFont(font_game);
  quit_text.setCharacterSize(30);
  quit_text.setFillColor(sf::Color(0, 0, 0, 255));
  quit_text.setPosition
    (
      window.getSize().x - window.getSize().x/3 - quit_text.getGlobalBounds().width/2 - window.getSize().x/20,
      window.getSize().y/2 - quit_text.getGlobalBounds().height/2
    );

  /*--------------------------------------------------------------------------*/

  // GAME

  // BG GAME
  if (!background_texture_game.loadFromFile("Data/Images/background.png"))
  {
    std::cout << "Background texture not loaded\n";
    return false;
  }
  background_game.setTexture(background_texture_game);
  background_game.setScale
    (
      window.getSize().x / background_game.getGlobalBounds().width,
      window.getSize().y / background_game.getGlobalBounds().height
    );
  background_game.setPosition(0, 0);

  // Character 1
  if (!character_1_texture.loadFromFile("Data/Images/elephant.png"))
  {
    std::cout <<"Character 1 texture not loaded\n";
    return false;
  }
  character_1.setTexture(character_1_texture);
  character_1.setPosition(window.getSize().x/2 - character_1.getGlobalBounds().width/2 -30,
                          window.getSize().y/2 - character_1.getGlobalBounds().height/2 -30);
  character_1.setScale(1.5, 1.5);
  speed_1_x = (rand() % speed_1_max + speed_1_min) * randomizer_x();
  speed_1_y = (rand() % speed_1_max + speed_1_min) * randomizer_y();

  // Character 2
  if (!character_2_texture.loadFromFile("Data/Images/buffalo.png"))
  {
    std::cout <<"Character 2 texture not loaded\n";
    return false;
  }
  character_2.setTexture(character_2_texture);
  character_2.setPosition(0 + character_2.getGlobalBounds().width/4,
                          0 + character_2.getGlobalBounds().height/4);
  character_2.setScale(0.7, 0.7);
  speed_2_x = (rand() % speed_2_max + speed_2_min) * randomizer_x();
  speed_2_y = (rand() % speed_2_max + speed_2_min) * randomizer_y();

  // Character 3
  if (!character_3_texture.loadFromFile("Data/Images/owl.png"))
  {
    std::cout <<"Character 3 texture not loaded\n";
    return false;
  }
  character_3.setTexture(character_3_texture);
  character_3.setPosition(window.getSize().x - window.getSize().x/10 - character_3.getGlobalBounds().width/2,
                          window.getSize().y - window.getSize().y/10 - character_3.getGlobalBounds().height/2);
  character_3.setScale(0.5,0.5);
  speed_3_x = (rand() % speed_3_max + speed_3_min) * randomizer_x();
  speed_3_y = (rand() % speed_3_max + speed_3_min) * randomizer_y();

  // Character 4
  if (!character_4_texture.loadFromFile("Data/Images/ball.png"))
  {
    std::cout <<"Character 3 texture not loaded\n";
    return false;
  }
  character_4.setTexture(character_4_texture);
  character_4.setPosition(window.getSize().x/2 - character_4.getGlobalBounds().width/2,
                          window.getSize().y - character_4.getGlobalBounds().height - window.getSize().y/20);
  speed_4_x = (rand() % speed_4_max + speed_4_min) * randomizer_x();
  speed_4_y = (rand() % speed_4_max + speed_4_min) * randomizer_y();

  // Score
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  score_text.setString("Score: " + std::to_string(score));
  score_text.setFont(font_game);
  score_text.setCharacterSize(30);
  score_text.setFillColor(sf::Color(0, 0, 0, 255));
  score_text.setPosition
    (
      window.getSize().x - score_text.getGlobalBounds().width - window.getSize().x/20,
      -0

    );

  // Timer
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  time_text.setString("Timer: " + std::to_string(timer));
  time_text.setFont(font_game);
  time_text.setCharacterSize(30);
  time_text.setFillColor(sf::Color(0, 0, 0, 255));
  time_text.setPosition
    (
      0 + window.getSize().x/40,
      -0

    );

  return true;
}

/*============================================================================*/

// Game Main Function
void Game::update(float dt)
{
  // Stops the game if in menu
  if (is_running)
  {
    // Timer
    timer_func(dt);

    // Character 1 Movements
    if ((character_1.getPosition().x >= (window.getSize().x - character_1.getGlobalBounds().width))
        || (character_1.getPosition().x <= 0))
    {
      reverse_x_1 = !reverse_x_1;
    }
    if (reverse_x_1)
    {
      character_1.move(-speed_1_x*dt, 0);

    }
    else
    {
      character_1.move(speed_1_x*dt, 0);

      character_1.setTextureRect(sf::IntRect
                                 (0,
                                  0,
                                  character_1.getLocalBounds().width,
                                  character_1.getLocalBounds().height));
    }

    if ((character_1.getPosition().y >= (window.getSize().y - character_1.getGlobalBounds().height))
        || (character_1.getPosition().y <= 0))
    {
      reverse_y_1 = !reverse_y_1;
    }
    if (reverse_y_1)
    {
      character_1.move(0, -speed_1_y*dt);
    }
    else
    {
      character_1.move(0, speed_1_y*dt);
    }

    // Character 2 Movements
    if ((character_2.getPosition().x >= (window.getSize().x - character_2.getGlobalBounds().width))
        || (character_2.getPosition().x <= 0))
    {
      reverse_x_2 = !reverse_x_2;
    }
    if (reverse_x_2)
    {
      character_2.move(-speed_2_x*dt, 0);
    }
    else
    {
      character_2.move(speed_2_x*dt, 0);
    }

    if ((character_2.getPosition().y >= (window.getSize().y - character_2.getGlobalBounds().height))
        || (character_2.getPosition().y <= 0))
    {
      reverse_y_2 = !reverse_y_2;
    }
    if (reverse_y_2)
    {
      character_2.move(0, -speed_2_y*dt);
    }
    else
    {
      character_2.move(0, speed_2_y*dt);
    }


    // Character 3 Movements
    if ((character_3.getPosition().x >= (window.getSize().x - character_3.getGlobalBounds().width))
        || (character_3.getPosition().x <= 0))
    {
      reverse_x_3 = !reverse_x_3;
    }
    if (reverse_x_3)
    {
      character_3.move(-speed_3_x*dt, 0);
    }
    else
    {
      character_3.move(speed_3_x*dt, 0);
    }

    if ((character_3.getPosition().y >= (window.getSize().y - character_3.getGlobalBounds().height))
        || (character_3.getPosition().y <= 0))
    {
      reverse_y_3 = !reverse_y_3;
    }
    if (reverse_y_3)
    {
      character_3.move(0, -speed_3_y*dt);
    }
    else
    {
      character_3.move(0, speed_3_y*dt);
    }

    // Character 4 Movements
    if ((character_4.getPosition().x >= (window.getSize().x - character_4.getGlobalBounds().width))
        || (character_4.getPosition().x <= 0))
    {
      reverse_x_4 = !reverse_x_4;
    }
    if (reverse_x_4)
    {
      character_4.move(-speed_4_x*dt, 0);
    }
    else
    {
      character_4.move(speed_4_x*dt, 0);
    }

    if ((character_4.getPosition().y >= (window.getSize().y - character_4.getGlobalBounds().height))
        || (character_4.getPosition().y <= 0))
    {
      reverse_y_4 = !reverse_y_4;
    }
    if (reverse_y_4)
    {
      character_4.move(0, -speed_4_y*dt);
    }
    else
    {
      character_4.move(0, speed_4_y*dt);
    }

    // Stops Game when timer is 0
    if (timer <= 0)
    {
      end_screen_text.setString("Well done, you earned: " + std::to_string(score) +
                                      " points!\n\n"
                                      "            Can you do better?");
      is_running = false;
      end_screen = true;
    }
  }
}

/*============================================================================*/

// Rendering Function
void Game::render()
{
  // Main Menu Render
  if (start_menu)
  {
    window.draw(background_menu);
    window.draw(title_text);
    window.draw(rules_text);
    window.draw(play_option);
    window.draw(quit_option);
  }

  // In Game Render
  else if (is_running)
  {
    window.draw(background_game);
    window.draw(title_text);
    window.draw(score_text);
    window.draw(time_text);
    window.draw(character_3);
    window.draw(character_2);
    window.draw(character_1);
    window.draw(character_4);
  }

  // Esc Menu Render
  else if (play_again_menu)
  {
    window.draw(background_esc_menu);
    window.draw(title_text);
    window.draw(pause_text);
    window.draw(restart_text);
    window.draw(quit_escape);
  }

  // Win Screen Render
  else if (end_screen)
  {
    window.draw(end_screen_bg);
    window.draw(title_text);
    window.draw(end_screen_text);
    window.draw(play_again_text);
    window.draw(quit_text);
  }

  // Error
  else
  {
    std::cout<< "Rendering Error";
  }

}

/*============================================================================*/

// Mouse Inputs
void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // check if in bounds of text
  if (start_menu)
  {
    if (collisionCheckText(click, play_option))
    {
      timer = max_timer;
      start_menu = false;
      is_running = true;
    }
    if (collisionCheckText(click, quit_option))
    {
      window.close();
    }
  }
  if (play_again_menu)
  {
    if (collisionCheckText(click, restart_text))
    {
      score = 0;
      score_text.setString("Score: " + std::to_string(score));
      timer = max_timer;
      play_again_menu = false;
      is_running = true;
    }
    if (collisionCheckText(click, quit_escape))
    {
      window.close();
    }
  }
  if (end_screen)
  {
    if (collisionCheckText(click, play_again_text))
    {
      score = 0;
      score_text.setString("Score: " + std::to_string(score));
      timer = max_timer;
      end_screen = false;
      is_running = true;
    }
    if (collisionCheckText(click, quit_text))
    {
      window.close();
    }
  }

  // check if in bounds of bird Sprite
  if (is_running)
  {
    if (collisionCheck(click, character_1))
    {
      spawn_1();
      score++;
      score_text.setString("Score: " + std::to_string(score));
      return;
    }
    if (collisionCheck(click, character_2))
    {
      spawn_2();
      score = score + 2;
      score_text.setString("Score: " + std::to_string(score));
      return;
    }
    if (collisionCheck(click, character_3))
    {
      spawn_3();
      score = score + 3;
      score_text.setString("Score: " + std::to_string(score));
      return;
    }
    if (collisionCheck(click, character_4))
    {
      spawn_4();
      score = score - 6;
      score_text.setString("Score: " + std::to_string(score));
      return;
    }
  }
}

/*============================================================================*/

// Keyboard Inputs
void Game::keyPressed(sf::Event event)
{
  // Allows Keybord Input in Start Menu
  if (start_menu)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;
      if(play_selected)
      {
        play_option.setString(">Play<");
        play_option.setStyle(sf::Text::Italic | sf::Text::Bold);
        quit_option.setString("Quit");
        quit_option.setStyle(sf::Text::Regular);
      }
      else
      {
        play_option.setString("Play");
        play_option.setStyle(sf::Text::Regular);
        quit_option.setString(">Quit<");
        quit_option.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        timer = max_timer;
        start_menu = false;
        is_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // Allows Keybord Input in Esc Menu
  if (play_again_menu)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;

      if(play_selected)
      {
        restart_text.setString(">Restart<");
        restart_text.setStyle(sf::Text::Italic | sf::Text::Bold);
        quit_escape.setString("Quit");
        quit_escape.setStyle(sf::Text::Regular);
      }
      else
      {
        restart_text.setString("Restart");
        restart_text.setStyle(sf::Text::Regular);
        quit_escape.setString(">Quit<");
        quit_escape.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        score = 0;
        score_text.setString("Score: " + std::to_string(score));
        timer = max_timer;
        play_again_menu = false;
        is_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // Allows Keybord Input in End Screen
  if (end_screen)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;
      if(play_selected)
      {
        play_again_text.setString(">Play Again<");
        play_again_text.setStyle(sf::Text::Italic | sf::Text::Bold);
        quit_text.setString("Quit");
        quit_text.setStyle(sf::Text::Regular);
      }
      else
      {
        play_again_text.setString("Play Again");
        play_again_text.setStyle(sf::Text::Regular);
        quit_text.setString(">Quit<");
        quit_text.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        score = 0;
        score_text.setString("Score: " + std::to_string(score));
        timer = max_timer;
        end_screen = false;
        is_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // Opens/Closes Esc Menu
  if (event.key.code == sf::Keyboard:: Escape)
  {
    if (is_running)
    {
      is_running = false;
      play_again_menu = true;
    }
    else if (play_again_menu)
    {
      play_again_menu = false;
      is_running = true;
    }
  }
}

/*============================================================================*/

// Mouse Collision Check
bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
  if (click.x > sprite.getPosition().x
      && click.y > sprite.getPosition().y
      && click.x < sprite.getPosition().x + sprite.getGlobalBounds().width
      && click.y < sprite.getPosition().y + sprite.getGlobalBounds().height)
  {
    return true;
  }

  else
  {
  return false;
  }
}

bool Game::collisionCheckText(sf::Vector2i click, sf::Text text)
{
  if (click.x > text.getPosition().x
      && click.y > text.getPosition().y
      && click.x < text.getPosition().x + text.getGlobalBounds().width
      && click.y < text.getPosition().y + text.getGlobalBounds().height)
  {
    return true;
  }

  else
  {
    return false;
  }
}

/*============================================================================*/

// Respawn Functions
void Game::spawn_1()
{
  int x = window.getSize().x - character_1.getGlobalBounds().width;
  int y = window.getSize().y - character_1.getGlobalBounds().height;

  character_1.setPosition(0 + rand() % x,
                          0 + rand() % y);
  speed_1_x = (rand() % speed_1_max + speed_1_min) * randomizer_x();
  speed_1_y = (rand() % speed_1_max + speed_1_min) * randomizer_y();
}
void Game::spawn_2()
{
  int x = window.getSize().x - character_2.getGlobalBounds().width;
  int y = window.getSize().y - character_2.getGlobalBounds().height;

  character_2.setPosition(0 + rand() % x,
                          0 + rand() % y);
  speed_2_x = (rand() % speed_2_max + speed_2_min) * randomizer_x();
  speed_2_y = (rand() % speed_2_max + speed_2_min) * randomizer_y();
}
void Game::spawn_3()
{
  int x = window.getSize().x - character_3.getGlobalBounds().width;
  int y = window.getSize().y - character_3.getGlobalBounds().height;

  character_3.setPosition(0 + rand() % x,
                          0 + rand() % y);
  speed_3_x = (rand() % speed_3_max + speed_3_min) * randomizer_x();
  speed_3_y = (rand() % speed_3_max + speed_3_min) * randomizer_y();
}
void Game::spawn_4()
{
  int x = window.getSize().x - character_4.getGlobalBounds().width;
  int y = window.getSize().y - character_4.getGlobalBounds().height;

  character_4.setPosition(0 + rand() % x,
                          0 + rand() % y);
  speed_4_x = (rand() % speed_4_max + speed_4_min) * randomizer_x();
  speed_4_y = (rand() % speed_4_max + speed_4_min) * randomizer_y();
}

/*============================================================================*/

// Directions Randomizer
int Game::randomizer_x()
{
  int sign = rand() % 2;
  if (sign == 0)
  {
    int random_d = -1;
    return random_d;
  }
  else
  {
    int random_d = 1;
    return random_d;
  }
}
int Game::randomizer_y()
{
  int sign = rand() % 2;
  if (sign == 0)
  {
    int random_d = -1;
    return random_d;
  }
  else
  {
    int random_d = 1;
    return random_d;
  }
}

/*============================================================================*/

// Timer Manager
float Game::timer_func(float dt)
{
  timer = timer - dt;
  int time_int = timer;
  std::stringstream time_stream;
  time_stream << std::fixed <<std::setprecision(2)<<timer;
  std::string dec_time = time_stream.str();

  if (timer >= timer_threshold)
  {
  time_text.setString("Timer: " + std::to_string(time_int));
  }
  else
  {
    time_text.setString("Timer: " + dec_time);
  }
}
