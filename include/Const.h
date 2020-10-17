#pragma once
#include <SFML/Graphics.hpp>

//-----------------Menu Consts-------------------
const int NUMBER_OF_MAIN__MENU_ITEMS = 3;
const int MENU_IMAGES = 2;
const int MAIN_MENU_BACK = 0;
const int HELP_BACKGROUND = 1;

//-----------------Borad Consts-------------------
const char FIRE = 'F';
const char PISTOL_AMMO = '1';
const char SHOTGUN_AMMO = '2';
const char MACHINE_GUN_AMMO = '3';
const char PLASME_RIFLE_AMMO = '4';
const char BFG_AMMO = '5';

const char SMALL_HEALTH = '6';
const char BIG_HEALTH = '7';
const char ULTRA_HEALTH = '8';

const char ARMOR = '@';

const char SLAYER = 'S';
const char BARON = 'B';
const char CACODEMON = 'C';
const char REVENANT = 'R';
const char CYBERDEMON = 'D';
const char HEAVY_WEAPON_DUDE = 'H';
const char MANCUBUS = 'M';

const char VER_WALL = '|';
const char HORI_WALL = '_';
const char DIAG_WALL_R = '>';
const char DIAG_WALL_L = '<';

//consts for texture vector
const int NUM_OF_TEXTURES = 45;
const int NUM_OF_SOUNDS = 45;
const int NUM_OF_MUSIC = 2;
const int NUM_OF_FONTS = 2;

const int DEMON_ACTION_SOUNDS = 4;

enum DemonActionSound
{
    ON_SIGHT,
    ATTACKING,
    DEATH,
    INJURED,

};

enum Fonts
{
    OLD_DOOM_FONT,
    NEW_DOOM_FONT,
};
enum Music
{
    MENU_MUSIC,
    GAME_MUSIC,
};
enum Sounds
{
    BARON_ATTACK_SOUND,
    BARON_DEATH_SOUND,
    BARON_INJURED_SOUND,
    BFG_FIRE_SOUND,
    BFG_HIT_SOUND,
    CACODEMON_ATTACK_SOUND,
    CACODEMON_DEATH_SOUND,
    CACODEMONE_INJURED_SOUND,
    CHAINGUN_FIRE_SOUND,
    CYBERDEMON_HIT_SOUND,
    CYBERDEMON_DEATH_SOUND,
    CYBERDEMON_INJURED_SOUND,
    H_W_D_ATTACK_SOUND,
    H_W_D_DEATH_SOUND,
    H_W_D_INJURED_SOUND,
    ITEMP_PICKUP_SOUND,
    PISTOL_FIRE_SOUND,
    REVENANT_ATTACK_SOUND,
    REVENANT_DEATH_SOUND,
    REVENANT_INJURED_SOUND,
    SHOTGUN_FIRE_SOUND,
    SLAYER_DEATH_SOUND,
    SLAYER_INJURED_SOUND,
    BARON_SIGHT_SOUND,
    CACODEMON_SIGHT_SOUND,
    CYBERDEMON_SIGHT_SOUND,
    MANCUBUS_ATTACK_SOUND,
    MANCUBUS_DEATH_SOUND,
    MANCUBUS_INJURED_SOUND,
    MANCUBUS_SIGHT_SOUND,
    PLASMA_SHOT_SOUND,
    REVENANT_SIGHT_SOUND,
    SLAYER_DASH_SOUND,
    ARMOR_PICKUP_SOUND,
    AMMO_PICKUP_SOUND,
    H_W_D_SIGHT_SOUND,
    MANCUBUS_HIT_SOUND,
    CYBERDEMON_SHOT_SOUND,
    UNSTOPABLE_SOUND,
    HUMILIATION_SOUND,

    KILLING_SPREE_SOUND,
    DOUBLE_KILL_SOUND,
    GODLIKE_SOUND,
    MULTI_KILL_SOUND,
    ULTRA_KILL_SOUND,
};

enum Textures
{
    PLAYER_TEXTURE,
    FIRE_TEXTURE,
    MACHINE_GUN_AMMO_TEXTURE,
    BARON_OF_HELL_TEXTURE,
    BFG_SHOT_TEXTURE,
    PISTOL_SHOT_TEXTURE,
    SHOTGUN_SHOT_TEXTURE,
    BFG_EXP_TEXTURE,
    TOOLBAR_TEXTURE,
    ARMOR_TEXTURE,
    CACODEMON_TEXTURE,
    REVENANT_TEXTURE,
    SHOTGUN_AMMO_TEXTURE,
    PISTOL_AMMO_TEXTURE,
    PLASME_RILE_AMMO_TEXTURE,
    SMALL_HEALTH_TEXTURE,
    BIG_HEALTH_TEXTURE,
    ULTRA_HEALTH_TEXTURE,
    WEAPONS_TEXTURE,
    VER_WALL_TEXTURE,
    HORI_WALL_TEXTURE,
    DIAGONAL_LEFT_WALL_TEXTURE,
    CYBERDEMON_TEXTURE,
    HEAVY_WEAPON_DUDE_TEXTURE,
    MACHINE_GUN_BULLET_TEXTURE,
    BFG_AMMO_TEXTURE,
    MANCUBUS_TEXTURE,
    ARACHNOTRON_TEXTURE,
    PLASME_RIFLE_SHOT_TEXTURE,
    DUDE_SHOT_TEXTURE,
    OPTIONS_LOGOE_TEXTURE,
    MANCUBUS_SHOT_TEXTURE,
    MANCUBUS_BLAST_TEXTURE,
    CYBERDEMON_SHOT_TEXTURE,
    CYBERDEMON_BLAST_TEXTURE,
    DASH_TEXTURE,
    LEVEL_ONE_BACK_TEXTURE,
    LEVEL_TOW_BACK_TEXTURE,
    LEVEL_THREE_BACK_TEXTURE,
    END_GAME_PHOTO_TEXTURE,
    KEYS_HELP_PHOTO_TEXTURE,
    ARMORY_HELP_PHOTO_TEXTURE,
    DEMONS_HELP_PHOTO_TEXTURE,
    MAIN_MENU_PHOTO_TEXTURE,
    HELP_MENU_BACK_PHOTO_TEXTURE,
};

//-----------------Sounds Consts-------------------
/*
const int MUSIC_FILES = 2;
const int MENU_MUSIC = 0;
const int IN_GAME_MUSIC = 1;*/

const int REGULAR_SLAYER_SPEED = 420;
const int DASH_SPEED = 1400;


//-----------------Controller Consts-------------------
//const sf::Keyboard::Key ESCAPE = sf::Keyboard::Key::Escape;
const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 1000;

//-----------------Color Consts-------------------
const sf::Color GREY_COLOR = sf::Color::Color(100, 100, 100);
const sf::Color GOLD_COLOR = sf::Color::Color(0xFF, 0xD7, 0x00);
const sf::Color GOLD_COLOR2 = sf::Color::Color(0xDA, 0xA5, 0x20);
const sf::Color DARK_RED_COLOR = sf::Color::Color(0x8B, 0x00, 0x00);
const sf::Color MED_RED_COLOR = sf::Color::Color(0xC7, 0x15, 0x85);
const sf::Color DARK_GREY_COLOR = sf::Color::Color(0xA9, 0xA9, 0xA9);

//-----------------Player Consts-------------------

//static atributes ------------
const int ARMOR_ATRIBUTE = 100;
const int HELMET_ATRIBUTE = 50; //?
const int SMALL_HEALTH_ATRIBUTE = 40;
const int BIG_HEALTH_ATRIBUTE = 80;
const int ULTRA_HEALTH_ATRIBUTE = 200;

//movement---
const int SLAYER_DOWN = 0;
const int SLAYER_DOWN_LEFT = 42;
const int SLAYER_LEFT = 89;
const int SLAYER_UP_LEFT = 144;
const int SLAYER_UP = 186;

//DAMAGES-------------------------



//volume consts-----------------
const int MENU_VOLUME = 80;
const int GAME_VOLUME = 20;

//shoot Direction-------------
const int SHOT_DOWN = 180;
const int SHOT_DOWN_LEFT = 225;
const int SHOT_LEFT = -90;
const int SHOT_UP_LEFT = -45;
const int SHOT_UP = 0;
const int SHOT_UP_RIGHT = 45;
const int SHOT_RIGHT = 90;
const int SHOT_DOWN_RIGHT = 135;


//---------------
//background
const int NUM_OF_BACK = 4;
const sf::Vector2f FIRST_BACK_LOC = sf::Vector2f(-500, -500);
const sf::Vector2f SECOND_BACK_LOC = sf::Vector2f(9500, -500);
const sf::Vector2f THIRD_BACK_LOC = sf::Vector2f(-500, 9500);
const sf::Vector2f FOURTH_BACK_LOC = sf::Vector2f(9500, 9500);


enum Direction
{
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    STOP,
};

const int NUM_OF_WEAPONS = 5;
enum Weapon
{
    PISTOL,
    SHOTGUN,
    CHAIN_GUN,
    PLASMA_RIFLE,
    BFG,
};

const int TOOLBAR_TEXTS = 4;
const int AMMO_TEXT = 0;
const int HEALTH_TEXT = 1;
const int ARMOR_TEXT = 2;
const int DASH_TEXT = 3;

//DAMAGES---------------
const int FIRE_DAMAGE = 5;

const int BIG_BOOM = 3;
const int BFG_SHOT = 0;
const int BFG_HIT = 0;
const int MANCUBUS_SHOT = 1;
const int MANCUBUS_HIT = 1;
const int CYBERDEMON_SHOT = 2;
const int CYBERDEMON_HIT = 2;

//inGameMessages-----------------------
const int NUM_OF_MESSEGAS = 6;
const std::string DIED_MESSAGE = "youre dead";
const std::string STARTING_MESSAGE = "get ready";
const std::string WIN_MESSAGE = "you finished the game";
const std::string RESTART_MESSAGE = "do you wish to continue?\n                 press y/n";
const std::string LEVEL_COMPLETE_MESSAGE = "level completed";
const std::string LOADING_NEXT_MESSAGE = "          get ready\nfor the next level";
const std::string PAUSED_MESSAGE = "paused";

const int DIED = 0;
const int WIN = 1;
const int RESTART = 2;
const int LEVEL_COMPLETE = 3;
const int LOADING = 4;
const int STARTING = 5;

const int RESTART_MSGS = 0;
const int LEVEL_COMPLETE_MSGS = 1;
const int END_GAME_MSGS = 2;
const int START_MSGS = 3;

const std::string END_OF_LEVEL = "END"; //marks the end of a level
const std::string END_GAME = "END_GAME"; //marks the end of the game
const int IN_GAME_PHOTOS = 2;
const int LOGO = 0;
const int END_GAME_PHOTO = 1;

const std::string ESCAPE_TEXT = "press escape\nto go back";
const std::string INSTRUCTION_TEXT = "                 slay all the demons\nin each level to progress in the game";
const std::string FULL_SCREEN_TEXT = "it is advised to play\non full screen mode\nfor better experiance\n(use the resize button)";
const int HELP_TEXTS = 3;
const int ESCAPE_MESSAGE = 0;
const int INSTRUCTION_MESSAGE = 1;
const int FULL_SCREEN_MESSAGE = 2;


const int PLAY_BUTTON = 0;
const int HELP_BUTTON = 1;
const int QUIT_BUTTON = 2;

const int HELP_MENU_PHOTOS = 4;

const int CONTROLS_BUTTON = 2;

const int ARMORY_BUTTON = 0;

const int DEMONS_BUTTON = 1;

const int BACKGROUND = 3;

const int DUDE_RANGE = 500;
const int MANCUBUS_RANGE = 650;
const int CYBERDEMON_RANGE = 700;
