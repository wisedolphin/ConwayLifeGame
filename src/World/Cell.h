#pragma once
struct Cell {
public:
    Cell(const bool condition = false)
    {
        life_ = condition;
        living_neighbors_ = 0;
    }
    bool is_life() const
    {
        return this->life_;
	}
    bool& set_life()
    {
        return this->life_;
	}
    unsigned& set_living_neighbors()
    {
		return living_neighbors_;
	}
    unsigned living_neighbors() const
    {
		return living_neighbors_;
	}
private:
    bool life_ = false;
	unsigned living_neighbors_ = 0;
};
