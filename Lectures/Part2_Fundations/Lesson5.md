# Extending the OpenStreetMap Data Model

## OpenStreetMap Data

The OpenStreetMap data that you will be using for this project comes in the form of an OSM XML file (.osm file). A sample of an OSM XML file from the OpenStreetMap Wiki is provided below.

The XML file contains several element types which are important to the code you will be writing: Nodes, Ways, and Relations.

### Nodes

A node is one of the most basic elements in the OpenStreetMap data model. Each node indicates a single point with an identifier `id`, latitude `lat`, and longitude `lon`.  

### Ways

A way is an ordered list of nodes that representes a feature in the map. This feature could be a road, or a boundary of a park, or some other feature in the map. 

### Relations

A relation is a data structure which documents a relationship between other data elements. 

Example from the OpenStreetMap wiki include: 
1. A route relation with lists the ways that from a major highway, cycle route, or bus route. 
2. A multipolygon that describes an area with holes, where the outer and inner boundaries of the area are given by two ways. 
   

## IO2D Starter Code

You are now ready to look at the starter code that you'll be using for the project. This code comes from a map rendering example in the Github repo for the 2D Graphics Library, IO2D. You will be extending the code to search for and display a path between two points on the map.

### Code Structure
The starter code for the project can be found here. This code is already loaded into a workspace, and you will not need to download or run the code locally to do the project. It may be a good idea to open the repository in a different tab and follow along as you read through the descriptions below, however. In the repo, you should see the following five directories:

**cmake**

This directory contains some CMakeLists.txt files that are needed for the project to find necessary libraries. You will not need to work with this directory for this project.

**instructions**

This directory contains a set of markdown instruction files for the exercises. Again, you will not need to work directly with the files here, but each set of instructions will be displayed in the terminal workspace for the appropriate exercise as you work on the project.

**src**

The source code for the project is contained here, and this is where you will be doing all of the project work. See below for more information about the contents of this directory.

**test**

This directory contains unit tests for various exercises, implemented using the Google Test framework. As you are developing your code, it may be helpful to look at the relevant test in this directory to see the expected answer and corresponding code. If your code fails a test, the console will tell you which file contains the failing test.

**thirdparty**

This directory contains third party libraries that have been included with this project. You will not need to work directly with this code.