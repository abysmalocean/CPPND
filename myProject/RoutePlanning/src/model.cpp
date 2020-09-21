#include "model.h"
#include "pugixml.hpp"
#include <iostream>
#include <string_view>
#include <cmath>
#include <algorithm>
#include <assert.h>


Model::Model(const std::vector<std::byte> &xml)
{
    LoadData(xml); 
}

void Model::LoadData(const std::vector<std::byte> &xml)
{
    using namespace pugi; 

    xml_document doc; 
    
}