#include <optional>
#include <fstream>
#include <vector>
#include <string>
#include <io2d.h>
#include "route_model.h"

using namespace std::experimental; 

// return as optional means the function may or may not return the desire
// value
static std::optional<std::vector<std::byte>>
ReadFile (const std::string &path)
{
    // read the osm data
    std::ifstream is{path, std::ios::binary | std::ios::ate}; 
    if( !is )
    {
        return std::nullopt; 
    }
    auto size = is.tellg(); 
    std::vector<std::byte> contents(size); 

    is.seekg(0); 
    is.read((char*)contents.data(), size); 

    if ( contents.empty() )
    {
        return std::nullopt; 
    }

    return std::move(contents);
}

int main(int argc, const char **argv)
{
    std::cout << "Starting the Route Planning Project " << std::endl; 
    std::string osm_data_file = "";
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (std::string_view{argv[i]} == "-f" && ++i < argc)
            {
                osm_data_file = argv[i]; 
            }
        }
    } else
    {
        std::cout << "To specify a map file use the following format: " 
                  << std::endl;
        std::cout << "Usage: [executable] [-f filename.osm]" << std::endl;
        // using the default osm file storage place. 
        osm_data_file = "../map.osm";
    }

    std::vector<std::byte> osm_data; 

    // read the osm file
    if ( osm_data.empty() && !osm_data_file.empty() )
    {
        std::cout << "Reading OpenStreetMap data from the following file : " << 
            osm_data_file << std::endl; 
        auto data = ReadFile(osm_data_file);
        if (!data)
        {
            std::cout << "Failed to read the data " << std::endl;
        } else
        {
            std::cout << "successful read the data from the file " << std::endl;
            osm_data = std::move(*data);
        }
    }

    // TODO 1: declare floats 'start_x', 'start_y', and 'end_x', 'end_y' and 
    // get user input for these values using std::cin, pass the user input to
    // the RouterPlanner object below in place of 10, 10, 90, 90.

    // Build Model
    RouteModel model{osm_data};

    return 1;

    
}