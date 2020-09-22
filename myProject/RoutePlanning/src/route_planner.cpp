#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, 
                           float       start_x, 
                           float       start_y, 
                           float       end_x  , 
                           float       end_y)
    : m_Model(model) 
{
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    // TODO 2: Use the m_Model.FindClosestNode method to find the 
    //         closest nodes to the starting and ending coordinates.
    //         Store the nodes you find in the RoutePlanner's start_node 
    //         and end_node attributes.

}

// TODO 3: Implement the CalculateHValue method.
// Tips:
// - You can use the distance to the end_node for the h value.
// - Node objects have a distance method to determine the distance to
//   another node.

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) 
{

}


