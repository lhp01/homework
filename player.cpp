#include "player.h"

//direction =1,2,3 for 上下左
void Player::move(int direction, int steps){
    switch (direction){
        case 1:
            this->setPosY(this->posY() - steps );
            break;
        case 2:
            this->setPosY(this->posY() + steps );
            break;
        case 3:
            this->setPosX(this->posX() - steps );
            break;
    }
}

