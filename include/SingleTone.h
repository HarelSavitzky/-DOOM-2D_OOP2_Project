#pragma once
//--------------------include Section --------------------
#include "Const.h"
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <unordered_map>
#include <iostream>

//--------------------SingleTone Class definition -------------------- 
//bad name, "Resources" / "Media" would be better
class SingleTone
{
public:

    static SingleTone& instance();

    SingleTone(const SingleTone&) = delete;
    SingleTone& operator=(const SingleTone&) = delete;

    const sf::Texture& texture(int texture) const { return m_objectsTexture[texture]; };

    std::unique_ptr<sf::Sound>& getSound(int id);
    std::unique_ptr<sf::Music>& getMusic(int id);
    std::unique_ptr<sf::Font>& getFont(int id);

private:
    SingleTone();

    void defineTextures();
    void defineSounds();
    void defineMusic();
    void defineFonts();

    sf::SoundBuffer m_soundBuffer [NUM_OF_SOUNDS];

    std::unordered_map <int, std::unique_ptr<sf::Music>> m_music;
    std::unordered_map <int, std::unique_ptr<sf::Sound>>  m_soundMap;
    std::unordered_map <int, std::unique_ptr<sf::Font>>  m_fontMap;
    
    std::vector<sf::Texture> m_objectsTexture;
};
