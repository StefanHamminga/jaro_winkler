#include <string>
#include <iostream>

#include "../jaro_winkler.hpp"

int main() {
    std::string a { "DWAYNE" };
    std::string b { "DUANE" };
    // std::string a { "abcde" };
    // std::string b { "abdcde" };

    std::cout << "Similarity for '" << a
              << "' and '" << b
              << "': " << edit_distance::jaro_winkler(a, b)
              << std::endl;

    std::cout << "Similarity for 'MARTHA' and 'MARHTA': "
              << edit_distance::jaro_winkler("MARTHA", "MARHTA")
              << std::endl;
    std::cout << "Similarity for 'DIXON' and 'DICKSONX': "
              << edit_distance::jaro_winkler("DIXON", "DICKSONX")
              << std::endl;
    std::cout << "Similarity for 'JELLYFISH' and 'SMELLYFISH': "
              << edit_distance::jaro_winkler("JELLYFISH", "SMELLYFISH")
              << std::endl;
}
