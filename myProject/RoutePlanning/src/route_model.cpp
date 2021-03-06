#include "route_model.h"
#include <iostream>

// the constructor inheriant the Model. 

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml)
{
    // Create RouteModel nodes
    int counter = 0; 
    for (Model::Node node : this->Nodes())
    {
        m_Nodes.emplace_back(Node(counter, this, node)); 
        ++counter; 
    }
    CreateNodeToRoadHashmap(); 
}

void RouteModel::CreateNodeToRoadHashmap()
{
    for (const Model::Road &road : Roads())
    {
        if (road.type != Model::Road::Type::Footway)
        {
            for (int node_idx : Ways()[road.way].nodes)
            {
                if (node_to_road.find(node_idx) == node_to_road.end())
                {
                    node_to_road[node_idx] = std::vector<const Model::Road *> ();
                }
                node_to_road[node_idx].push_back(&road); 
            }
        }
    }

}