#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player {
        int t;
        
        public:
            Scientist(Board& board, City city, int num) : Player(board, city, "Scientist"), t(num)  {}
            Player& discover_cure(Color) override;
    };
};
