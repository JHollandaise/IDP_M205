#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include <string>
#include <vector>
#include <map>

class MotionControl {
public:

    std::vector<std::vector<int>> GetAllPaths(const int start, const int end, std::vector<int> path, int depth);

    std::vector<std::vector<int>> GetAllPaths(const int start, const int end);

    std::vector<int> GetShortestPath(std::vector<std::vector<int>> paths);
private:


    // table nodes and lines
    // ie { {"Node name",{"Connected node 1", "Connected node 2",...}, {...} }

    std::map<int,std::vector<int> > track_graph = {

            {1,{9}},
            {2,{9}},
            {3,{9}},

            {4,{13}},
            {5,{13}},
            {6,{13}},

            {9,{1,2,3,10}},
            {13,{4,5,6,12}},

            {10,{9,11}},
            {12,{13,11}},
            {11,{10,12,0}},

            {7,{0}},
            {8,{0}},

            {0,{7,8,11}}
    };

    // distance between points on table
    // ie { {"Node name",{ { "Connected node",distance(mm)}, {...} } }, {...} }
    std::map<int,std::map<int, int> > link_dists = {
            {9,{ {1,1},{2,1},{3,1},{10,1} }},
            {13,{ {4,1},{5,1},{6,1},{12,1} }},

            {11,{ {10,1},{12,1},{0,1} }},

            {0,{ {7,1},{8,1} }}
    };
};


#endif //IDP_M205_MOTIONCONTROL_H
