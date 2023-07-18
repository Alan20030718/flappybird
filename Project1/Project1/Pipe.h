#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;

class Pipe
{
private:


public:
	Pipe();
	~Pipe();
	void createPipe(Texture* texture1, Texture* texture2);
	void updatePipe();
	void DrawPipe(RenderTarget& target);
};

