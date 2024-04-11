#include "gol.h"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <ctime>
#include <vector>

Gol::Gol(int width_, int height_,)
    : width{ width_ }
    , height{ height_ }
    , grid_current{}
    , grid_next{}
    , grid_visual{}
{
reset();
}
void Gol::reset() {
    grid_current.clear();
    grid_current.resize(static_cast<std::sixe_t>(height), std::vecror<bool>(width));
    grid_next.clear();
    grid_current.resize(static_cast<std::sixe_t>(height), std::vecror<bool>(width));
    init_vasuals();
    seed_grid();

}
void Gol::init_vasuals(){
    grid_visual.clear();
    grid_visual.resize(width * height);
    int pos 0;
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            grid_visual[pos].position = sf::Vector2f(static_cast<float>(x),
                                                         static_cast<float>(y));
            grid_visual[pos++].color = visual_dead;
        }
    }
}

void Gol::seed_grid(){
    std::uniform_int_distribution<int> m_axis(0, height - 1);
    std::uniform_int_distribution<int> n_axis(0, height - 1);
    std::uniform_int_distribution<int> cells(width * height/2, width*height);

    int initial_cell_nr = cells(rng);
    while (initial_cell_nr > 0){
        std::size_t m = m_axis(rng);
        std::size_t n = n_axis(rng);
        if (!grid_next[m][n]){
            grid_next[m][n] = true;
            grid_visual[m * width + width + n].color = visual_alive;
            --initial_cell_nr;
        }
    }
}