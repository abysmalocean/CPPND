#ifndef ROUTE_MODEL_H
#define ROUTE_MODEL_H

#include <limits>
#include <cmath>
#include <unordered_map>
#include <iostream>
#include "model.h"

class RouteModel : public Model
{

public: 
    class Node : public Model::Node
    {
        Node() {}
    };
    RouteModel(const std::vector<std::byte> &xml); 

private: 
    std::vector<Node> m_Nodes; 

}; 

#endif
