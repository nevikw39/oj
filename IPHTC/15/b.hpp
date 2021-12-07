#include <sstream>

void IdiotSandwich::print(std::ostream &out) { out << "An idiot sandwich with intelligence level " << intelligence << " only."; }

void NormalSandwich::print(std::ostream &out) { out << name << ". Masterpiece of sandwiches."; }

std::istream &operator>>(std::istream &in, Dish &d)
{
    std::string s;
	while (in && !s.length())
    	std::getline(in, s);
    std::stringstream ss(s);
    ss >> s;
    int intelli;
    if (ss >> intelli)
        d.food = new IdiotSandwich(intelli);
    else
        d.food = new NormalSandwich(s);
    return in;
}

Dish::~Dish()
{
	if (food)
		delete food;
}
