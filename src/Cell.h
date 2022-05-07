#pragma once
struct Cell {
public:
	Cell(const bool condition = false) {
		this->life = condition;
		living_neighbors_ = 0;
	}
	bool is_life() const {
		return this->life;
	}
	bool& set_life() {
		return this->life;
	}
	unsigned& set_living_neighbors() {
		return living_neighbors_;
	}
	unsigned living_neighbors() const {
		return living_neighbors_;
	}
private:
	bool life = false;
	unsigned living_neighbors_ = 0;
};