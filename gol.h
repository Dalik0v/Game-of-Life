#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Gol{
public: 
    Gol(int width_, int height_);
    void display_grid(sf::RebderWindow& window) const;
    void update();
    void reset();
private:
    int count_neighboors(int i, int j) const;
    void apply_rules(int neighboors, int i, ini j);
    void  init_vasuals();
    void  seed_grid();
    int width;
    int height;
    vectr<vector<bool>> grid_current;
    vector<vector<bool>> grid_next;
    vector<sf::Vertex> grid_visual;

    mt19937 rng;   
    sf::Color visual_alive = sf::Color::white;
    sf::Color visual_dead = sf::Color::Black;

};

