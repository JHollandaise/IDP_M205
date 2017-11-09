#include <iostream>
#include "MotionControl.h"


std::vector<std::vector<MotionControl::NodeName>>
MotionControl::GetAllPaths(const NodeName start, const NodeName end, std::vector<NodeName> path)
{

    std::vector<std::vector<NodeName>> succesful_paths;

    path.push_back(start);

    if (start == end) {
        succesful_paths.push_back(path);
        return succesful_paths;
    }

    std::vector<std::vector<NodeName>> paths;

    if (track_graph.find(start)==track_graph.end())
    {
        std::cout<<"node not in track";
    }

    for (auto adjacent_node : track_graph[start])
    {
        if (std::find(path.begin(), path.end(), adjacent_node) == path.end() )
        {
            auto new_paths = GetAllPaths(adjacent_node, end, path);

            for (const auto current_path: new_paths)
            {
                succesful_paths.push_back(current_path);
            }
        }
    }

    return succesful_paths;
}


std::vector<std::vector<MotionControl::NodeName>>
MotionControl::GetAllPaths(const NodeName start, const NodeName end)
{
    return GetAllPaths(start, end, {});
}

std::vector<MotionControl::NodeName> MotionControl::GetShortestPath(std::vector<std::vector<NodeName>> paths)
{
    std::vector<NodeName> shortest_path {};
    int shortest_path_size;

    for (const auto current_path : paths)
    {
        if (paths.size() == 0) return {};

        if (!shortest_path_size || current_path.size() < shortest_path_size)
        {
            shortest_path_size = current_path.size();
            shortest_path = current_path;
        }
    }

    return shortest_path;
}

int MotionControl::straight_on() {
    return 0;
}

int MotionControl::turn_left() {
    return 0;
}

int MotionControl::turn_right() {
    return 0;
}
