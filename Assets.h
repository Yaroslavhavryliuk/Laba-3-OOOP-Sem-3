#pragma once
#include <SFML/Graphics.hpp>
/**
\brief Class for work with resources of the game

In this class we have an object of the class Font for the type calibri and public 
method Load for downloading. This class was realised as singleton of Mayers
*/
class Assets
{
public:
	sf::Font font; ///< The type calibri
public:
	static Assets& Instance()
	{
		static Assets s;
		return s;
	}
	/// download the type calibri
	void Load();
private:
	Assets() {};
	~Assets() {};
	Assets(Assets const&) = delete;
	Assets& operator= (Assets const&) = delete;
};
