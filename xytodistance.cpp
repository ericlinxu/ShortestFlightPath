#include "xytodistance.hpp"
#include "readFromFile.hpp"
#include<iostream>
#include<vector>
#include<cmath>

using std::vector;
using std::string;
using std::pair;

#define pi 3.14159265358979323846

vector<pair<double, double>> getCoordinates(string airports_file) {
    vector<string> airports = file_to_vector(airports_file);
    vector<pair<double, double>> latlong;
    double lat = 0;
    double lont = 0;
    for (string airport : airports) {
        size_t pos = airport.find(",");
        for (size_t i = 0; i < 6; i++) {
            pos = airport.find(",", pos + 1);
            if (i == 4) {
                size_t size = airport.find(",", pos + 1) - pos - 1;
                lat = atof(airport.substr(pos + 1, size).c_str());
            }
            if (i == 5) {
                size_t size = airport.find(",", pos + 1) - pos - 1;
                lont = atof(airport.substr(pos + 1, size).c_str());
            }
        }
        latlong.push_back(pair<double, double> (lat, lont));
    }
    return latlong;
}

double toRad(double degree) {
    return degree/180 * pi;
}

double getDistance(pair<double, double> sloc, pair<double, double> dloc) {
    sloc.first = toRad(sloc.first);
    sloc.second = toRad(sloc.second);
    dloc.first = toRad(dloc.first);
    dloc.second = toRad(dloc.second);
    double u = sin((dloc.first - sloc.first)/2);
    double v = sin((dloc.second - sloc.second)/2);
    return 2.0 * 6371 * asin(sqrt(u * u + cos(sloc.first) * cos(dloc.first) * v * v));
}