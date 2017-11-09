#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include <string>
#include <vector>
#include <map>

class MotionControl {
public:

    enum  NodeName  {
        S,
        D1, D2, D3,
        D4, D5, D6,
        P1, P2,
        Dl, Tl,
        Ts,
        Tr, Dr,
    };

    // returns all possible node paths to traverse from node start to node end
    std::vector<std::vector<NodeName>> GetAllPaths(const NodeName start, const NodeName end, std::vector<NodeName > path);
    std::vector<std::vector<NodeName>> GetAllPaths(const NodeName start, const NodeName end);


    // shortest path from vector of node paths
    std::vector<NodeName> GetShortestPath(std::vector<std::vector<NodeName>> paths);



private:

    int straight_on();

    int turn_left();

    int turn_right();



    // table nodes and lines
    // ie { {Node name,{Connected node 1, Connected node 2, ...}, {...} }

    std::map<NodeName ,std::vector<NodeName> > track_graph = {
            {NodeName::D1,{NodeName::Dl}},
            {NodeName::D2,{NodeName::Dl}},
            {NodeName::D3,{NodeName::Dl}},

            {NodeName::D4,{NodeName::Dr}},
            {NodeName::D5,{NodeName::Dr}},
            {NodeName::D6,{NodeName::Dr}},

            {NodeName::Dl,{NodeName::D1,NodeName::D2,NodeName::D3,NodeName::Tl}},
            {NodeName::Dr,{NodeName::D4,NodeName::D5,NodeName::D6,NodeName::Tr}},

            {NodeName::Tl,{NodeName::Dl,NodeName::Ts}},
            {NodeName::Tr,{NodeName::Dr,NodeName::Ts}},
            {NodeName::Ts,{NodeName::Tl,NodeName::Tr,NodeName::S}},

            {NodeName::P1,{NodeName::S}},
            {NodeName::P2,{NodeName::S}},

            {NodeName::S,{NodeName::P1,NodeName::P2,NodeName::Ts}}
    };

    // actions to take on arriving at / leaving a node
    // ie {node value, { { {functions_on_arriving} , {functions_on_leaving} }}
    std::map<int, std::vector<std::vector<int (MotionControl::*)()>>> node_actions = {
            {NodeName::S, { {&MotionControl::turn_right}, {&MotionControl::straight_on}}},
            {NodeName::D1, { {&MotionControl::turn_right}, {&MotionControl::straight_on}}},


    };


};


#endif
