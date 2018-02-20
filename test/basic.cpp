#include <string>
#include <iostream>

#include "../jaro_winkler.hpp"

int main() {
    std::string a { "DWAYNE" };
    std::string b { "DUANE" };

    std::cout << "Similarity for '" << a
              << "' and '" << b
              << "': " << edit_distance::jaro_winkler(a, b, 0, .1)
              << std::endl;
}
