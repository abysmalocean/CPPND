# pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <cstddef>

class Model
{
public: 
    struct Node
    {
        double x = 0.0f;
        double y = 0.0f;
    }; 

    struct Way
    {
        std::vector<int> nodes; 
    };

    struct Road
    {
        enum Type
        {
            Invald, 
            Unclassified, 
            Service, 
            Residential, 
            Tertiary, 
            Secondary, 
            Primary,
            Trunk, 
            Motorway,
            Footwat
        }; 
        int way; 
        Type type; 
    };

    struct Railway
    {
        int way; 
    };

    struct Multipolygon
    {
        std::vector<int> outer; 
        std::vector<int> inner; 
    }; 

    struct Building : Multipolygon {}; 
    struct Leisure  : Multipolygon {}; 
    struct Water    : Multipolygon {}; 
    struct Landuse  : Multipolygon 
    {
        enum Type 
        {
            Invalid, 
            Commercial, 
            Construction, 
            Grass, 
            Forest, 
            Industrial, 
            Railway, 
            Residential
        };

        Type type; 
    };

    Model ( const std::vector<std::byte> & xml );

private: 
    void LoadData(const std::vector<std::byte> &xml); 
}; 