#pragma once
#include "Cell.h"
#include <iostream>
#include <algorithm>


struct World_field {
    // ctor
	explicit World_field(size_t size_row, size_t size_col)
		: size_row_(size_row)
		, size_col_(size_col)
		, array_(new Cell*[size_row_]) 
	{
        for (size_t i = 0; i != size_row_; i++)
        {
			array_[i] = new Cell[size_col_];
		}
	}
    // copy ctor
	World_field(World_field const& other)
		: size_row_(other.size_row_)
		, size_col_(other.size_col_)
		, array_(new Cell* [size_row_])
	{
        for (size_t i = 0; i != size_row_; i++)
        {
			array_[i] = new Cell[size_col_];
		}
        for (size_t i = 0; i != size_row_; i++)
        {
            for (size_t j = 0; j != size_col_; j++)
            {
				array_[i][j] = other.array_[i][j];
			}
		}
	}
    // dtor
	~World_field() 
	{
        for (size_t i = 0; i != size_row_; i++)
        {
			delete[] array_[i];
		}
		delete[] array_;
	}
	// swap_method
	void swap(World_field& other) 
	{
		std::swap(size_row_, other.size_row_);
		std::swap(size_col_, other.size_col_);
		std::swap(array_, other.array_);
	}
	// = operator
	World_field& operator=(World_field const& other) 
	{
        if (this != &other)
        {
			World_field(other).swap(*this);
		}
		return *this;
	}
    // move ctor
	World_field(World_field&& other) noexcept
		: size_row_(other.size_row_)
		, size_col_(other.size_col_)
		, array_(other.array_)
	{
		other.size_row_ = 0; 
		other.size_col_ = 0;
		other.array_ = nullptr;
	}
    // = operator move
	World_field& operator=(World_field&& other) noexcept 
	{
        if (this != &other)
        {
            this->~World_field();
            this->size_col_ = 0;
            this->size_row_ = 0;
            this->array_ = nullptr;
			swap(other);
		}
		return *this;
	}
	// Fill world field with initial conditions
    //Passing 2d array by reference https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
	template<size_t Rows, size_t Cols>
    void set_world(const Cell(&some_world)[Rows][Cols])
    {
        if (Rows != size_row_ || Cols != size_col_)
        {
            throw(std::string("Cant set world!\n Sizes are incomparable!\n"));
		}
        for (size_t i = 0; i != size_row_; i++)
        {
            for (size_t j = 0; j != size_col_; j++)
            {
				array_[i][j] = some_world[i][j];
			}
		}
	}
    //call count_living_neighbors for each Cell inside
	void count_living_neighbors_for_each_cell();
	// Print world to cli
	void print_field() const;
	// () operator overload - setter
	Cell& operator()(size_t i, size_t j);
	// () operator overload - getter
	Cell operator()(size_t i, size_t j) const;
	// Size getters
	size_t size_row() const;
	size_t size_col() const;
	// Evolve this world to next generation of the world
	void evolve(World_field& next_world);


private:
	size_t size_row_;
	size_t size_col_;
	Cell** array_;
};

//count living neighbors for the [n_row, n_col] Cell
unsigned count_living_neighbors(World_field const& World, int const& n_row, int const& n_col);
