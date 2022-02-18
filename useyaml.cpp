#include <fstream>
#include <iostream>
#include <iomanip>

#include <yaml-cpp/yaml.h>

int main() {
    // Reading some inputs from a yaml config file
    const auto config = YAML::LoadFile("config.yaml");

    // Loading the information we need
    const auto name = config["star"].as<std::string>();
    const auto model = config["model"].as<std::string>();
    const auto metallicity = config["metallicity"].as<float>();
    const auto RA = config["coordinates"]["RA"];

    // Printing some useful information
    std::cout << "Star: " << name << "\nModel: "<< model << std::endl;
    std::cout << "Coordinates: RA\n" << RA << std::endl;
    std::cout << "Metallicity: " << std::setprecision(9) << metallicity << std::endl;

    // Saving the results back in a yaml file
    std::ofstream output("result.yaml");
    YAML::Emitter emitter(output);
    emitter << YAML::BeginDoc << YAML::BeginMap 
        << YAML::Key << "Met"
        << YAML::Value << metallicity
        << YAML::EndMap << YAML::EndDoc;

    return 0;
}
