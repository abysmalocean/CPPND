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

        // distance between this node and other node
        float distance(const Node& other) const
        {
          return std::sqrt(std::pow(x - other.x , 2) + std::pow(y - other.y, 2)); 
        }

        // find all the neighbours, modifies the beighbours
        void FindNeighbors(); 


      private:
        // Add private Node variables and methods here.
        int index;
        RouteModel * parent_model = nullptr;

        Node* FindNeighbor(std::vector<int> node_indices); 
        
    };
    
    std::vector<Node>& SNodes() {return m_Nodes; }
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.
    std::unordered_map<int, std::vector<const Model::Road*>>& getNode_to_road()
    {
      return node_to_road; 
    }
    
    Node& FindClosestNode(float x, float y); 
    
  private:
    // m_Nodes: store all of the nodes from the OpenStree Map Data
    std::vector<Node> m_Nodes;
    std::unordered_map<int, std::vector<const Model::Road*>> node_to_road; 

    void CreateNodeToRoadHashmap(); 



};
