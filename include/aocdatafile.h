#pragma once
#include <fstream>
#include <vector>

namespace aoc {

class aocdatafile {
public:
    aocdatafile(std::string _basefilename, std::string _extension)
        : basefilename(_basefilename)
        , extension(_extension)
    {
        filename = basefilename.substr(0, basefilename.rfind(".")+1) + _extension;

        std::ifstream infile(filename);

        std::string line;
        while (std::getline(infile, line)) {
            lines.push_back(line);
        }

        std::cout << "Input file: " << filename << ", lines: " << lines.size()
                  << std::endl;
    }

    long getXSize() { return lines[0].size(); }
    long getYSize() { return lines.size(); }

    std::vector<std::string> getLines()
    {
        return lines;
    }

    std::vector<std::vector<std::string>> getVectors()
    {
        std::vector<std::vector<std::string>> ret;

        for (auto elem : lines)
            ret.push_back(stringtovector(elem, ' '));

        return ret;
    }

    aocmap getAOCMap()
    {
        return aocmap(lines);
    }

private:
    std::string basefilename;
    std::string extension;
    std::string filename;
    std::vector<std::string> lines;
};

} // namespace aoc