#include <fstream>
#include <iostream>
#include <iomanip>

#include <json.hpp>

int main() {
    // Reading some inputs from a json config file
    std::ifstream input("config.json");
    nlohmann::json config;
    input >> config;

    // Loading the information we need
    const auto name = config["star"].get<std::string>();
    const auto model = config["model"].get<std::string>();
    const auto metallicity = config["metallicity"].get<float>();
    const auto RA = config["coordinates"]["RA"];

    // Printing some useful information
    std::cout << "Star: " << name << "\nModel: "<< model << std::endl;
    std::cout << "Coordinates: RA\n" << RA << std::endl;
    std::cout << "Metallicity: " << std::setprecision(9) << metallicity << std::endl;

    // Saving the results back in a json file
    std::ofstream output("result.json");
    nlohmann::json result;
    result["metallicity"] = metallicity;
    output << result.dump(4) << std::endl;

    return 0;
}
