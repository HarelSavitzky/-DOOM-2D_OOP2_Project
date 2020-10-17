#include "SingleTone.h"
//---------------SingleTone Constructor--------------------
SingleTone::SingleTone()
{
	defineTextures();
	defineMusic();
	defineSounds();
	defineFonts();
}
//---------------inctance function--------------------
SingleTone& SingleTone::instance()
{
	static SingleTone instance;
	return instance;
}
//-----------------------------get resources functions--------------------------------------
//mostly with maps and unique ptrs

//---------------getSound function--------------------
std::unique_ptr<sf::Sound>& SingleTone::getSound(int id)
{
	auto it = m_soundMap.find(id);
	if (it == m_soundMap.end())
		std::cout << "unable to load sound" << std::endl;	//this will never happen ...
	
	return it->second; 
}
//---------------getMusic function--------------------
std::unique_ptr<sf::Music>& SingleTone::getMusic(int id)
{
	auto it = m_music.find(id);
	if (it == m_music.end())
		std::cout << "unable to load music" << std::endl;
	
	return it->second;
}
//---------------getFont function--------------------
std::unique_ptr<sf::Font>& SingleTone::getFont(int id)
{
	auto it = m_fontMap.find(id);
	if (it == m_fontMap.end())
		std::cout << "unable to load font" << std::endl;
	
	return it->second;
}
//---------------defineTextures function--------------------
//function to define the textures , also pretty generic, easy to insert a new texture
void SingleTone::defineTextures()
{
	const char* FILE_NAMES[NUM_OF_TEXTURES] = { "Slayer.png" , "dynamicFire.png",
	"machineGunAmmo.png", "hellKnight.png", "BFGshot.png", "machineGunBullet.png",
	"shotGunbullet.png", "BFGexp2.png", "toolbar.png", "Armor.png",
	"cacodemon.png","Revenant.png", "shotgunAmmo.png" , "pistolAmmo.png" , "BFGAmmo.png",
	"smallHealth.png" ,"bigHealth.png" ,"ultraHealth.png", "weapons.png", "verWall.png",
	"horiWall.png" , "DiagonalLeftWall.png", "Cyberdemon.png", "HeavyWeaponDude.png",
	"machineGunBullet5.png", "PlasmaRifleAmmo.png","Mancubus.png", "Arachnotron.png",
	"PlasmaShot2.png", "HWDshot.png", "OptionsLogo.png","mancubusShot.png",
	"mancubusBlast.png","cyberdemonShot.png","cyberdemonBlast.png", "dash.png",
	"back.jpg","back2.jpg","back3.jpg", "endGame.jpg", "keysHelp.png", "armoryHelp.png",
	"monstersHelp.png", "doomback.jpg", "helpBack.jpg" };

	for (int i = 0; i < NUM_OF_TEXTURES; i++)
	{
		sf::Texture temp;
		m_objectsTexture.push_back(temp);

		if (!m_objectsTexture[i].loadFromFile(FILE_NAMES[i]))
			throw std::runtime_error("Can't load file");

		m_objectsTexture[i].setSmooth(true);
	}
}
//---------------defineSounds function--------------------
//function to define the sounds , also pretty generic, easy to insert a new sound
void SingleTone::defineSounds()
{
	const char* SOUND_FILE_NAMES[NUM_OF_SOUNDS] = {"baronattack.wav", "barondeath.wav", "baroninjured.wav",
	"bfgfire.wav","bfghit.wav","cacodemonattack.wav","cacodemondeath.wav","cacodemoninjured.wav",
	"chaingunfire.wav","cyberdemonattack.wav","cyberdemondeath.wav","cyberdemoninjured.wav",
	"hwgattack.wav","hwgdeath.wav","hwginjured.wav","itempickup.wav","pistolfire.wav","revenantattack.wav",
	"revenantdeath.wav","revenantinjured.wav", "shotgunfire.wav","slayerdeath.wav", "slayerinjured.wav",
	"baronsight.wav", "cacodemonsight.wav","cyberdemonsight.wav", "mancubusattack.wav","mancubusdeath.wav",
	"mancubusinjured.wav", "mancubussight.wav", "plasmaRifle.wav", "revenantsight.wav", "slayerdash3.wav",
	"armorPickup.wav", "ammoPickUp.wav", "hwdsight.wav", "mancubushit.wav", "lasercyberdemon.wav",
	"unstopable.wav", "humiliation.oga" , "killingspree.ogg", "doublekill.ogg", "godlike.ogg",
	"multikill.wav", "ultrakill.wav" };

	for (int i = 0; i < NUM_OF_SOUNDS; i++)
	{
		if (!m_soundBuffer[i].loadFromFile(SOUND_FILE_NAMES[i]))
			throw std::runtime_error("Can't load sound");

		std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>(m_soundBuffer[i]);

		m_soundMap.emplace(i, std::move(sound));
	}
}
//---------------defineMusic function--------------------
//function to define the music , also pretty generic, easy to insert a new music
void SingleTone::defineMusic()
{
	const char* MUSIC_FILE_NAMES[NUM_OF_MUSIC] = { "MenuMusic.ogg" , "inGameMusic.ogg" };
	for (int i = 0; i < NUM_OF_MUSIC; i++)
	{
		std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();

		if (!music->openFromFile(MUSIC_FILE_NAMES[i]))
			throw std::runtime_error("Can't load music");

		m_music.emplace(i, std::move(music));
	}
}
//---------------defineFonts function--------------------
//function to define the fonts , also pretty generic, easy to insert a new one
void SingleTone::defineFonts()
{
	const char* FONT_FILE_NAMES[NUM_OF_MUSIC] = { "oldDoomFont.ttf" , "DoomFont.ttf" };

	for (int i = 0; i < NUM_OF_FONTS; i++)
	{
		std::unique_ptr< sf::Font> font = std::make_unique<sf::Font>();;

		if (!font->loadFromFile(FONT_FILE_NAMES[i]))
			throw std::runtime_error("Can't load font");

		m_fontMap.emplace(i, std::move(font));
	}
}
