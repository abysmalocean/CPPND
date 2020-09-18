#include <optional>
#include <fstream>
#include <vector>
#include <string>
#include <io2d.h>


int main(int argc, const char **argv)
{
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
        std::cout << "To specify a map file use the following format: " << std::endl;
        std::cout << "Usage: [executable] [-f filename.osm]" << std::endl;
        osm_data_file = "../map.osm";
    }

    std::vector<std::byte> osm_data; 

    
}