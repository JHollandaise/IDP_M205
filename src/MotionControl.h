#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include <string>
#include <vector>
#include <map>
#include "robot.h"


class MotionControl {

public:


    // @TODO check whether public methods should actually be private


    // points used to control the movement of the robot
    enum Node  {
        D1,D2,D3,D4,D5,D6,
        P1,P2,
        Su,Sr,Sl,Sd,

        P1Sr,P1Su,
        P2Sl,P2Su,

        SlP1,
        SrP2,

        SdP1,SdP2,

        SuTl,SuTr,

        TlTr,TlSd,
        TrTl,TrSd
    };

    // motion control and determination
    int ControlMotion(Node starting_node);
	
    typedef std::vector<Node> node_container;

    // describes all of the types of box
    enum box_type {
        open,
        short_circ,
        res1,
        res2,
        res3
    };

    // maps boxes to their respective destination(s)

    std::map<box_type, Node> box_dests = {
            {open,        D1},
            {short_circ,  D1},
            {res1,        D2},
            {res2,        D4},
            {res3,        D3}
    };

    // @TODO make private
    // returns all possible node paths to traverse from node start to node end
    std::vector<node_container> GetAllPaths(Node start, Node end, node_container path);
    std::vector<node_container> GetAllPaths(Node start, Node end);

    // shortest path from vector of node paths
    node_container GetShortestPath(std::vector<std::vector<Node> > paths);
    node_container GetShortestPath(Node start, Node end);


    // describes how many boxes are at each location
    // ie { {node, number of boxes at location} , {...} }
    std::map<Node,int> box_count = {
            {D1, 0},
            {D2, 0},
            {D3, 0},
            {D4, 0},
            {D5, 0},
            {D6, 0}
    };
    
    // ident box
    std::vector<MotionControl::box_type> IdentifyBoxes(int num_boxes);

private:

    //@TODO uncomment this
    Robot robot;

    std::vector<box_type> held_boxes;

    Node current_node;

    node_container current_path;

    // table nodes and lines
    // ie { {Node, {Connected node 1, Connected node 2, ...}, {...} }1

    std::map<Node ,node_container > track_graph = {
            {P1,{P1Su,P1Sr}},
            {P2,{P2Su,P2Sl}},

            {Sl,{SlP1}},
            {Sr,{SrP2}},
            {Sd,{SdP1,SdP2}},
            {Su,{SuTl,SuTr}},

            {D1,{TlTr,TlSd}},
            {D2,{TlTr,TlSd}},
            {D3,{TlTr,TlSd}},

            {D4,{TrTl,TrSd}},
            {D5,{TrTl,TrSd}},
            {D6,{TrTl,TrSd}},

            {P1Su,{Su}},
            {P1Sr,{Sr}},

            {P2Sl,{Sl}},
            {P2Su,{Su}},

            {SlP1,{P1}},

            {SrP2,{P2}},

            {SdP1,{P1}},
            {SdP2,{P2}},
            {SuTl,{D1,D2,D3}},
            {SuTr,{D4,D5,D6}},

            {TlTr,{D4,D5,D6}},
            {TlSd,{Sd}},

            {TrTl,{D1,D2,D3}},
            {TrSd,{Sd}}
    };

    // carries out the appropriate functions for a given node
    void Node_action(Node node);


};


#endif
