#include "MotionControl.h"


std::vector<std::vector<std::string>>*
MotionControl::GetShortestPath(const std::string start,const std::string end, std::vector<std::string> path) {

    path.push_back(start);

    if (start == end) return path * ;

    if (track_graph.find(start) == track_graph.end()) return nullptr;

    std::vector<std::vector<std::string> > paths = {};

    for (auto node = track_graph[start].begin(); node != track_graph[start].end(); node++) {
        if (std::find(path.begin(), path.end(), *node) == path.end()) {
            auto new_paths = GetShortestPath(*node, end, path);
            for (auto new_path = new_paths->begin(); new_path != new_paths->end(); new_path++) {
                paths.push_back(*new_path);
            }
        }
    }
}

std::vector<std::vector<std::string>> *MotionControl::GetShortestPath(std::string start, std::string end) {
    return GetShortestPath(start,end,{});
}
