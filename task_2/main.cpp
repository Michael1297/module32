#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main() {
    std::ifstream file("..\\films.json");
    if(!file.is_open()) return 0;
    nlohmann::json films;
    file >> films;

    std::string cast = "Robert Downey Jr.";

    for(nlohmann::json::iterator film = films.begin(); film != films.end(); film++){
        for(nlohmann::json::iterator casts = film.value()["Cast"].begin(); casts != film.value()["Cast"].end(); casts++){
            if(casts.value() == cast) std::cout << "\"" << film.key() << "\" " << casts.key() << "\n";
        }
    }
}
