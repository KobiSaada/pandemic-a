#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Medic: public Player {
        
        public:
            Medic(Board& board, City city) : Player(board, city, "Medic") {}
            Player& treat(City) override;
    };
};