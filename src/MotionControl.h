#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include <string>
#include <vector>
#include <map>
#include "robot.h"
class MotionControl {

public:
	
	MotionControl();

    // @TODO check whether public methods should actually be private


    // points used to control the movement of the robot
    // each node relates to a set of actions on the track in order to progress to the next node
    // ie node D1D2 describes the set of actions to traverse from D1 to D2
    enum Node  {
        D1,D2,D3,D4,D5,D6,
        P1,P2,
        Su,Sr,Sl,Sd,

        D1D2,D1D3, D2D1,D2D3, D3D1,D3D2,
        D4D5,D4D6, D5D4,D5D6, D6D4,D6D5,

        D1Dr,D2Dr,D3Dr,
        D4Dl,D5Dl,D6Dl,

        D1S,D2S,D3S,
        D4S,D5S,D6S,

        P1Sr,P1Su,
        P2Sl,P2Su,

        SlP1,
        SrP2,

        SuDl,SuDr,

        SSl,SSd,SSr
    };

    // motion control and determination
    int ControlMotion(Node starting_node);
	
    typedef std::vector<Node> node_container;

    // describes all of the types of electronics components box
    enum box_type {
        open,
        short_circ,
        res1,
        res2,
        res3
    };

    // maps boxes to their respective destination node(s)
    std::map<box_type, Node> box_dests;

    // @TODO make private
    // returns all possible node paths to traverse from node start to node end
    std::vector<node_container> GetAllPaths(Node start, Node end, node_container path);
    std::vector<node_container> GetAllPaths(Node start, Node end);

    // shortest path from vector of node paths
    node_container GetShortestPath(std::vector<std::vector<Node> > paths);
    // shortest path from node start to node end
    node_container GetShortestPath(Node start, Node end);


    // describes how many boxes are at each location
    // ie { {node, number of boxes at location} , {...} }
    std::map<Node,int> box_count;
    
    // ident box
    std::vector<MotionControl::box_type> IdentifyBoxes(int num_boxes);

    // returns the required destination node(s) of box
    Node GetDropOff(box_type box);

private:
	
	Robot robot;

    // box currently in bottom grip that has been identified
    box_type held_box;
    // number of boxes held by robot
    int num_boxes;

    // current postion of robot
    Node current_node;

    node_container current_path;

    // table nodes and links
    // ie { {Node, {Connected node 1, Connected node 2, ...}, {...} }
    std::map<Node ,node_container > track_graph;

    // carries out the appropriate functions for a given node
    void NodeAction(Node node);


};


#endif
