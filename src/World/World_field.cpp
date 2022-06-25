#include <iostream>
#include "Cell.h"
#include "World_field.h"

size_t World_field::size_row() const {
	return this->size_row_;
};
size_t World_field::size_col() const {
	return this->size_col_;
};

void World_field::print_field() const
{
	std::cout << "\n";
    for (size_t i = 0; i != size_row_; i++)
    {
        for (size_t j = 0; j != size_col_; j++)
        {
            if (array_[i][j].is_life())
            {
				std::cout << " * ";
			}
			else { std::cout << " - ";}
		}
		std::cout << std::endl;
	}
}

Cell& World_field::operator()(size_t i, size_t j)
{
    if (i < size_row_ && j < size_col_)
    {
		return array_[i][j];
	}
    else { throw std::out_of_range("Out of bounds!\n"); }
	
}
Cell World_field::operator()(size_t i, size_t j) const
{
    if (i < size_row_ && j < size_col_)
    {
		return array_[i][j];
	}
    else { throw std::out_of_range("Out of bounds!\n"); }
}

void World_field::count_living_neighbors_for_each_cell()
{
    for (size_t i = 0; i != size_row_; i++)
    {
        for (size_t j = 0; j != size_col_; j++)
        {
            array_[i][j].set_living_neighbors() = count_living_neighbors(*this, i, j);
		}
	}
}

void World_field::evolve(World_field &next_world) {
    for (size_t i = 0; i != size_row_; i++)
    {
        for (size_t j = 0; j != size_col_; j++)
        {
            if (array_[i][j].is_life())
            {
                if (array_[i][j].living_neighbors() > 3 || array_[i][j].living_neighbors() < 2)
               {
                    try{next_world(i,j).set_life() = false;}
                    catch(const std::out_of_range& oor)
                    {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                    }
				}
			}
			else {
                if (array_[i][j].living_neighbors() == 3)
                {
                    try{next_world(i, j).set_life() = true;}
                    catch(const std::out_of_range& oor)
                    {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                    }
				}
			}
		}
	}
}

unsigned count_living_neighbors(World_field const& World, int const& n_row, int const& n_col) {
	unsigned cnt = 0;
    //To_do
    //implicit conversion from size_t to int
    for (int i = n_row - 1; i <= n_row + 1; i++)
    {
        for (int j = n_col - 1; j <= n_col + 1; j++)
        {
            if (i < 0 || j < 0)
            {
				continue;
			}
            if (i >= World.size_row() || j >= World.size_col())
            {
				continue;
			}
            if (i == n_row && j == n_col)
            {
				continue;
			}
            if (World(i,j).is_life())
            {
				cnt += 1;
			}
		}
	}

	return cnt;
}
