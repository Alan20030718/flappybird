#include "pipe.h"
using namespace sf;

Pipe::Pipe(Texture* texture)
{
	
	this->pipe_pos = pipe_height[rand() % pipe_height.size()];
	//std::cout<<pipe_pos<<"\n";
	this->bot_pipe = this->pipe_pos;
	this->top_pipe = this->pipe_pos - 300;
	//this->pipe_t.loadFromFile("Textures/pipe-green");
	//this->pipe_s.setTexture(this->pipe_t);
	
}
void Pipe::Draw(RenderTarget& target)
{
	
}