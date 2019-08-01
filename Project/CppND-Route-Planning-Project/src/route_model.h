#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        // A pointer point to the parenet node; 
        Node* parent = nullptr; 
        // The g-value for the node.
        float g_value = 0.f; 
        //The h-value for the node.
        float h_value = std::numeric_limits<float>::max(); 
        // A boolean to indicate if the node has been visited.
        bool visited = false; 
        // A pointer verctor for the neighbors; 
        std::vector<Node*> neighbors; 
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}

                
      private:
        // Add private Node variables and methods here.
        int index;
        RouteModel * parent_model = nullptr;
        
    };
    
    std::vector<Node>& SNodes() {return m_Nodes; }
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

  private:
    // Add private RouteModel variables and methods here.
    // m_Nodes: store all of the nodes from the OpenStree Map Data
    std::vector<Node> m_Nodes;


};
