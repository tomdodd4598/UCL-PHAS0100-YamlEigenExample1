#include <fstream>
#include <iostream>
#include <iomanip>

#include <yaml-cpp/yaml.h>

int main() {
    // Reading some inputs from a yaml config file
    YAML::Node config = YAML::LoadFile("config.yaml");

    // Loading the information we need
    const std::string name = config["star"].as<std::string>();
    const std::string model = config["model"].as<std::string>();
    const float metallicity = config["metallicity"].as<float>();
    YAML::Node RA = config["coordinates"]["RA"];

    // Printing some useful information
    std::cout << "Star:" << name << "\nModel: "<< model << std::endl;
    std::cout << "Coordinates: RA\n" << RA << std::endl;
    std::cout << "Metallicity: " 
          << std::setprecision(9) << metallicity << std::endl;

    // Saving the results back in a yaml file
    std::ofstream output("result.yaml");
    YAML::Emitter emitter(output);
    emitter << YAML::BeginDoc << YAML::BeginMap 
        << YAML::Key << "Met" << YAML::Value 
        << metallicity // bug 469
        << YAML::EndMap << YAML::EndDoc;

    return 0;
}
