
#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  explicit Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
  bool collisionCheckText(sf::Vector2i click, sf::Text text);
  void spawn_1();
  void spawn_2();
  void spawn_3();
  void spawn_4();
  int randomizer_x();
  int randomizer_y();
  float timer_func(float dt);

  sf::RenderWindow& window;

  // General
  sf::Text title_text;
  sf::Font font_game;

  // Start Menu
  sf::Sprite background_esc_menu;
  sf::Texture background_texture_esc_menu;

  sf::Text play_option;
  sf::Text quit_option;

  sf::Font font_menu;
  sf::Text rules_text;

  bool play_selected = true;

  // Esc Menu
  sf::Sprite background_menu;
  sf::Texture background_texture_menu;
  sf::Text pause_text;
  sf::Text restart_text;
  sf::Text quit_escape;

  // End Screen
  sf::Text end_screen_text;
  sf::Sprite end_screen_bg;
  sf::Texture end_screen_bg_texture;
  sf::Text play_again_text;
  sf::Text quit_text;

  // Game States
  bool start_menu;
  bool play_again_menu;
  bool is_running;
  bool end_screen;

  // Game Variables
  sf::Sprite background_game;
  sf::Texture background_texture_game;

  sf::Text score_text;
  int score = 0;

  sf::Text time_text;
  float timer;
  float max_timer = 30.0f;
  int timer_threshold = 10;

  sf::Sprite character_1;
  sf::Texture character_1_texture;
  bool reverse_x_1 = false;
  bool reverse_y_1 = false;
  int speed_1_max = 100;
  int speed_1_min = 50;
  int speed_1_x;
  int speed_1_y;

  sf::Sprite character_2;
  sf::Texture character_2_texture;
  bool reverse_x_2 = false;
  bool reverse_y_2 = false;
  int speed_2_max = 200;
  int speed_2_min = 100;
  int speed_2_x;
  int speed_2_y;

  sf::Sprite character_3;
  sf::Texture character_3_texture;
  bool reverse_x_3 = false;
  bool reverse_y_3 = false;
  int speed_3_max = 300;
  int speed_3_min = 200;
  int speed_3_x;
  int speed_3_y;

  sf::Sprite character_4;
  sf::Texture character_4_texture;
  bool reverse_x_4 = false;
  bool reverse_y_4 = false;
  int speed_4_max = 200;
  int speed_4_min = 100;
  int speed_4_x;
  int speed_4_y;
};

#endif // WHACKAMOLESFML_GAME_H
