#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

double mapValue(double value) {
    return ((value - 1) * (2 - (-1)) / (5 - 1)) + (-1);
}

int main() {

    std::ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file " << std::endl;
        return 1;
    }


    std::vector<double> values;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        double value;
        if (iss >> value) {
            values.push_back(value);
        } else {
            std::cerr << "Error: Invalid data" << std::endl;
            return 1;
        }
    }
    inputFile.close();


    std::ofstream outputFile("result.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file " << std::endl;
        return 1;
    }


    outputFile << std::scientific << std::setprecision(17);


    outputFile << "# N Mean" << std::endl;
    double sum = 0.0;
    for (size_t i = 0; i < values.size(); ++i) {
        sum += mapValue(values[i]);
        double mean = sum / (i + 1);
        outputFile << i + 1 << " " << mean << std::endl;
    }
    outputFile.close();

    std::cout << "Result written to result.csv" << std::endl;

    return 0;
}
