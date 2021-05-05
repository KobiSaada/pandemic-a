#include "Board.hpp"

using namespace std;

namespace pandemic{


    int& Board::operator[](City city) {
        return Disease_level[city];
    }
    void Board::operator=(int n) {
}

    bool Board::is_clean(){return true;}
    // void Board::remove_cures(){}
    std::ostream& operator<<(std::ostream& os ,const Board& board) {cout << " oper << board\n"; return os;}
bool Board::is_connected(City &c, City &c1)
{
    return Neighbors_graph.at(c).contains(c1);
}
bool Board::has_research_station(City &city)
{
    return Research_station.find(city) != Research_station.end();
}
void Board::add_research_station(City city)
{
    Research_station.insert(city);
}
void Board::add_cure(Color color)
{
    _curesD.insert(color);
}
bool Board::have_cure(Color color) const
{
    return _curesD.find(color) != _curesD.end();
}
Color Board::city_color(City &city) 
{
    return city_colors.at(city);
}
void Board::remove_cures(){
    _curesD.clear();
}
}