#include "Pipe.h"

std::vector<std::pair<Sprite, Sprite>> PIPE;
std::vector<Sprite> PIPE_sc;
//std::vector<std::pair<Sprite, Sprite>> PIPE_sc;

Pipe::Pipe() {

}

Pipe::~Pipe() {

}

//Pipe update
void Pipe::updatePipe() {

    for (int i = 0; i < PIPE.size(); i++) {
        if (PIPE[i].first.getPosition().x < 0 - PIPE[i].first.getGlobalBounds().width) {
            auto itor = PIPE.erase(PIPE.begin() + i); 
        }
        else {
            PIPE[i].first.move(-2, 0);
            PIPE[i].second.move(-2, 0);
        }
    }
    for (int i = 0; i < PIPE_sc.size(); i++) {
        if (PIPE_sc[i].getPosition().x < 0 - PIPE_sc[i].getGlobalBounds().width) {
            auto itor = PIPE_sc.erase(PIPE_sc.begin() + i);
        }
        else {
            PIPE_sc[i].move(-2, 0);
        }
    }
}

//Spawn pipes
void Pipe::createPipe(Texture* texture1, Texture* texture2) {
    int _landHeight = 200;
    Sprite pipe_t(*texture1), pipe_b(*texture2), pipe_sc;
    pipe_b.scale(1.5, 2);
    pipe_t.scale(1.5, 2);
    int pos = (rand() % _landHeight + 200);
    pipe_t.setPosition(576, pos - 320 - 100);
    pipe_b.setPosition(576, pos + 320 + 100);
    pipe_sc.setPosition(576, 0);
    PIPE.push_back(std::make_pair(pipe_t, pipe_b));
    PIPE_sc.push_back(pipe_sc);
}

//Draw pipes
void Pipe::DrawPipe(RenderTarget& target)
{
    for (int i = 0; i < PIPE.size(); i++) {
        target.draw(PIPE[i].first);
        target.draw(PIPE[i].second);
    }
}

