#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
//#define NUM_OF_CARDS = 5;
using namespace std;

namespace pandemic {
    class Player {
        
        protected:
            Board board;
            City _Curr_city;
            std::string rol;
            std::set<City>_cards;

        public:
            Player(Board& b, City c, std::string r) : board(b), _Curr_city(c), rol(r) {
                std::set<City> playcardstmp;
                this->_cards = playcardstmp;
               // board=b;
            }
             Player();
        

            Player& drive(City c);
            Player(Board &b, City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City);
            Player& fly_shuttle(City);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            Player& take_card(City c);
            std::string role() {
                return rol;
            }
            
    
    };
    
};