# Extending the OpenStreetMap Data Model

## OpenStreetMap Data

The OpenStreetMap data that you will be using for this project comes in the form of an OSM XML file (.osm file). A sample of an OSM XML file from the OpenStreetMap Wiki is provided below.

The XML file contains several element types which are important to the code you will be writing: Nodes, Ways, and Relations.

### Nodes

A node is one of the most basic elements in the OpenStreetMap data model. Each node indicates a signle point with an identifier `id`, latitude `lat`, and logitude `lon`. 

### Ways

A way is an ordered list of nodes that representes a feature in the map. This feature could be a road, or a boundary of a park, or some other feature in the map. 

### Relations

A relation is a data structure which documents a relationship between other data elements. 

## IO2D Starter Code

