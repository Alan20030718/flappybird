#include "Pipe.h"

std::vector<std::pair<Sprite, Sprite>> PIPE;


Pipe::Pipe() {

}

Pipe::~Pipe() {

}

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

}

void Pipe::createPipe(Texture* texture1, Texture* texture2) {
    int _landHeight = 200;
    Sprite pipe_t(*texture1), pipe_b(*texture2);
    pipe_b.scale(1.5, 2);
    pipe_t.scale(1.5, 2);
    int pos = (rand() % _landHeight + 200);
    pipe_t.setPosition(576, pos - 320 - 80);
    pipe_b.setPosition(576, pos + 320 + 80);
    PIPE.push_back(std::make_pair(pipe_t, pipe_b));
}


void Pipe::DrawPipe(RenderTarget& target)
{
    for (int i = 0; i < PIPE.size(); i++) {
        target.draw(PIPE[i].first);
        target.draw(PIPE[i].second);
    }
}