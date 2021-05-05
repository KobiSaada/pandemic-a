#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "doctest.h"
#include <string>
#include <iostream>

using namespace std;
using namespace pandemic;
Board b;


TEST_CASE("test on player"){
	OperationsExpert player {b, City::Atlanta};  
	player.take_card(City::Johannesburg);
	player.take_card(City::Khartoum);
	player.take_card(City::SaoPaulo);
	player.take_card(City::BuenosAires);
	player.take_card(City::HoChiMinhCity);
    
    CHECK_NOTHROW((player.drive(City::Washington)));
    CHECK_THROWS((player.drive(City::Madrid)));

    
    CHECK_NOTHROW((player.fly_direct(City::Johannesburg)));
    CHECK_THROWS((player.fly_direct(City::Taipei)));
    b[City::Madrid] = 1;
    b[City::Johannesburg] = 2;
    player.treat(City::Johannesburg);
    CHECK((b[City::Johannesburg]==1));
    player.treat(City::Johannesburg);
    CHECK((b[City::Johannesburg]==0));
    CHECK_THROWS((player.treat(City::Johannesburg)));
    CHECK_THROWS((player.treat(City::Madrid)));

    
    player.take_card(City::Madrid);
    player.fly_direct(City::Madrid);
    CHECK_THROWS((player.discover_cure(Color::Blue)));
    player.take_card(City::Essen);
    player.take_card(City::Milan);
    player.take_card(City::Paris);
    player.take_card(City::London);
    player.take_card(City::NewYork);
    player.take_card(City::Madrid);
    CHECK_THROWS((player.discover_cure(Color::Blue)));
    player.build();
    CHECK_THROWS((player.discover_cure(Color::Black)));
    CHECK_NOTHROW((player.discover_cure(Color::Blue)));
    CHECK_THROWS((player.fly_direct(City::Milan)));

}

TEST_CASE("Board") {
    
    CHECK(b.is_clean() == true);
    b[City::Kinshasa] = 3;
    CHECK(b.is_clean() == false);
    CHECK_FALSE((b.is_clean())); 
    CHECK(b[City::Kinshasa]==3);     
	b[City::Kinshasa] = 2;
    CHECK(b[City::Kinshasa]==2);      
	b[City::MexicoCity] = 3;    
	b[City::HoChiMinhCity] = 1; 
	b[City::Chicago] = 1;
    CHECK(b[City::MexicoCity]==3);
    CHECK(b[City::Madrid]==0);
    b.remove_cures();
    CHECK((b.is_clean()));

    Medic m {b, City::Kinshasa};
    m.treat(City::Kinshasa);
    CHECK(b.is_clean() == true);

    b[City::Kinshasa] = 3;
    Dispatcher d {b, City::Kinshasa};
    d.treat(City::Kinshasa);
    d.treat(City::Kinshasa);
    d.treat(City::Kinshasa);
    CHECK(b.is_clean() == true);
    CHECK_THROWS(d.treat(City::Kinshasa));

    CHECK_NOTHROW(d.drive(City::Washington));
    CHECK_NOTHROW(d.drive(City::Atlanta));
    CHECK_NOTHROW(d.drive(City::Atlanta));

    CHECK_THROWS(d.drive(City::Bangkok));

    d.take_card(City::Moscow);
    CHECK_NOTHROW(d.fly_direct(City::Moscow));

    d.drive(City::Istanbul);
    d.take_card(City::Istanbul);
    CHECK_NOTHROW(d.fly_charter(City::Atlanta));


    CHECK_NOTHROW(d.build());
    CHECK_NOTHROW(d.drive(City::Miami));
    CHECK_NOTHROW(d.build());

    CHECK_NOTHROW(d.fly_shuttle(City::Atlanta));
}
TEST_CASE("Roles") {
    
    GeneSplicer g {b, City::Atlanta};
    CHECK(g.role() == "GeneSplicer");
    
    Medic m {b, City::Atlanta};
    CHECK(m.role() == "Medic");
    
    FieldDoctor f {b, City::Atlanta};
    CHECK(f.role() == "FieldDoctor");
    

    OperationsExpert o {b, City::Atlanta};
    CHECK(o.role() == "OperationsExpert");
    
    Researcher r {b, City::Atlanta};
    CHECK(r.role() == "Researcher");

    Dispatcher d {b, City::Atlanta};
    CHECK(d.role() == "Dispatcher");
    

    
    Virologist v {b, City::Atlanta};
    CHECK(v.role() == "Virologist");


}
