#include <iostream>
#include "MotionControl.h"


std::vector<std::vector<MotionControl::Node>>
MotionControl::GetAllPaths(const Node start, const Node end, std::vector<Node> path)
{

    // stores all found succesful paths
    std::vector<std::vector<Node>> succesful_paths;

    // adds current location (start) to current path being explored
    path.push_back(start);

    // if current location is the end of the desired path, add to successful_paths and return
    if (start == end) {
        succesful_paths.push_back(path);
        return succesful_paths;
    }

    // if node does not exist
    if (track_graph.find(start)==track_graph.end())
    {
        std::cout<<"node not in track";
    }

    // look at all the nodes adjacent to current node
    for (auto adjacent_node : track_graph[start])
    {
        // check the adjacent node is not already in path (ie don't retrace)
        if (std::find(path.begin(), path.end(), adjacent_node) == path.end() )
        {
            // make adjacent node current node and search paths from there
            // this is recursive and will end up returning all successful paths found to the depth 0 call
            auto new_paths = GetAllPaths(adjacent_node, end, path);

            // add all successful paths
            for (const auto current_path: new_paths)
            {
                succesful_paths.push_back(current_path);
            }
        }
    }

    return succesful_paths;
}


std::vector<std::vector<MotionControl::Node>>
MotionControl::GetAllPaths(const Node start, const Node end)
{
    return GetAllPaths(start, end, {});
}

std::vector<MotionControl::Node> MotionControl::GetShortestPath(std::vector<std::vector<Node>> paths)
{
    std::vector<Node> shortest_path {};

    // check some paths exist
    if (paths.empty()) return {};

    // length of the shortest path found (where length is the number of nodes traveled to)
    unsigned long shortest_path_size {};

    // look through all paths and compare against the currently shortest path found
    for (const auto current_path : paths)
    {

        if (!shortest_path_size || current_path.size() < shortest_path_size)
        {
            shortest_path_size = current_path.size();
            shortest_path = current_path;
        }
    }

    return shortest_path;
}


MotionControl::node_container MotionControl::GetShortestPath(MotionControl::Node start, MotionControl::Node end) {
    return GetShortestPath(GetAllPaths(start, end));
}

int MotionControl::ControlMotion(MotionControl::Node starting_node) {


    current_node = starting_node;

    int i = 0;
    while(i < 10) {
        // go from starting pos / end of drop off and get path to pick up boxes
        current_path = GetShortestPath(current_node, P1);

        // get to P1
        for (auto node : current_path) {
            Node_action(node);
        };

        // at P1 work out best path to drop of boxes that were picked up


        // go from P1 to drop off all boxes
        for (auto node : current_path) {
            Node_action(node);
        };


        i++;
    }

    // @TODO Go back to Start



    return 0;
}

void MotionControl::Node_action(MotionControl::Node node) {

    if (node==D1 || node==D2 || node==D3 || node==D4 || node==D5 || node==D6)
    {

        switch (node)
        {
            case D1 :
            case D6 :
                robot.JunctionAction(Robot::LEFT);
                break;
            case D5 :
            case D2 :
                robot.JunctionAction(Robot::STRAIGHT);
                break;
            case D3 :
            case D4 :
                robot.JunctionAction(Robot::RIGHT);
        }

        robot.FollowLine();
        robot.DropBoxes(3);

        robot.TurnDegrees(180.0);
        robot.FollowLine();

        switch (node)
        {
            case D1 :
            case D6 :
                robot.JunctionAction(Robot::RIGHT);
                break;
            case D5 :
            case D2 :
                robot.JunctionAction(Robot::STRAIGHT);
                break;
            case D3 :
            case D4 :
                robot.JunctionAction(Robot::LEFT);
        }
    }

    else if (node==P1)
    {
        robot.PickUpBoxes(3);
        held_boxes = robot.IdentifyBoxes(3);
        robot.TurnDegrees(180.0);
    }
}

std::vector<MotionControl::box_type> IdentifyBoxes(int num_boxes)
{
	return open;
}










