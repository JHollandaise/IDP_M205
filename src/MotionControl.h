#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include <string>
#include <vector>
#include <map>

class MotionControl {
public:
    MotionControl();

    std::vector<std::vector<std::string>>* GetShortestPath(std::string start, std::string end,
                                              std::vector<std::string> path = {});
    );

private:


    // table nodes and lines
    // ie { {"Node name",{"Connected node 1", "Connected node 2",...}, {...} }

    std::map<std::string,std::vector<std::string> > track_graph = {

            {"D1",{"Dl"}},
            {"D2",{"Dl"}},
            {"D3",{"Dl"}},

            {"D4",{"Dr"}},
            {"D5",{"Dr"}},
            {"D6",{"Dr"}},

            {"Dl",{"D1","D2","D3","Tl"}},
            {"Dr",{"D4","D5","D6","Tr"}},

            {"Tl",{"Dl","Ts"}},
            {"Tr",{"Dr","Ts"}},
            {"Ts",{"Tl","Tr","S"}},

            {"P1",{"S"}},
            {"P2",{"S"}},

            {"S",{"P1","P2","Ts"}}
    };

    // distance between points on table
    // ie { {"Node name",{ { "Connected node",distance(mm)}, {...} } }, {...} }
    std::map<std::string,std::map<std::string, int> > link_dists = {
            {"Dl",{ {"D1",1},{"D2",1},{"D3",1},{"Tl",1} }},
            {"Dr",{ {"D4",1},{"D5",1},{"D6",1},{"Tr",1} }},

            {"Ts",{ {"Tl",1},{"Tr",1},{"S",1} }},

            {"S",{ {"P1",1},{"P2",1} }}
    };
};


#endif //IDP_M205_MOTIONCONTROL_H
