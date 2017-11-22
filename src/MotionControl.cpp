#include <iostream>
#include "MotionControl.h"
#include <algorithm>

MotionControl::MotionControl(Robot robot) : robot(robot) {
}



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

    // look at all the nodes adjacent to current node
    for (const auto adjacent_node : track_graph[start])
    {
        // check the adjacent node is not already in path (ie don't retrace)
        if ( std::find(path.begin(), path.end(), adjacent_node) == path.end() )
        {
            // make adjacent node current node and search paths from there
            // this is recursive and will end up returning all successful paths found to the depth 0 call
            auto new_paths = GetAllPaths(adjacent_node, end, path);

            // add all successful paths
            for (const auto &current_path: new_paths)
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

std::vector<MotionControl::Node> MotionControl::GetShortestPath(std::vector<node_container> paths)
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

MotionControl::node_container MotionControl::GetShortestPath(MotionControl::Node start, MotionControl::Node end)
{
    return GetShortestPath(GetAllPaths(start, end));
}

int MotionControl::ControlMotion(MotionControl::Node starting_node)
{

    //initial path to pick up
    current_node = starting_node;
    Node end_node = P1;

    int j = 0;
    while(j<5) { //@TODO add functionality to check the timer is still okay
        // go from (starting pos/pickup/drop off) to (pick up/next drop off)
        current_path = GetShortestPath(current_node, end_node);

        for (auto node : current_path) {
            // checks that robot will not repeat action at the node it just arrived at
            if (node!=current_node) NodeAction(node);
        }

        // at Pickup/drop off work out best path to drop of boxes that were picked up
        // just picked up, get path from pick up to drop off
        // or still have boxes to drop off
        if (num_boxes > 0 )
        {
            // find where to drop next box
            end_node = GetDropOff(held_box);
        }
        // otherwise pick up more boxes
        else end_node = P1;

        j++;
    }

    // @TODO Go back to Start



    return 0;
}

void MotionControl::NodeAction(MotionControl::Node node)
{
    current_node = node;

    if (node==D1 || node==D2 || node==D3 || node==D4 || node==D5 || node==D6)
    {

        // operation at junction
        switch (node) {
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
            default:
                break;
        }

        // follow up to box
        robot.FollowLine();

        // box actions
        // drops off bottom box
        robot.DropBoxes(true); //@TODO this func could also back up a little

        box_count[node]++;
        num_boxes--;

        //@TODO add functionality to test the next box in the stack


        // approach junction
        robot.TurnDegrees(180.0);
        robot.FollowLine();

    }

    else if (node==P1 || node == P2)
    {
        switch(node)
        {
            case P1:
                // pick up whole stack of 3 boxes
                robot.PickUpBoxes(3);

                num_boxes = 3;
                break;
            case P2:
                // pick up 1 box
                robot.PickUpBoxes(1);

                num_boxes = 1;
                break;
            default:
                break;
        }

        // identify bottom box
        held_box = IdentifyBox(1);

        robot.TurnDegrees(180.0);
        robot.FollowLine();
    }

    else if (node==Su || node==Sr || node==Sd || node==Sl)
    {
        // only stop at start node if we want it to
        if (robot.ReturnToStart) robot.StopAtStart();
    }

    else if (node==P1Su || node== P1Sr || node== P2Su ||  node== P2Sl )
    {
        robot.FollowLine();

        switch (node)
        {
            case P1Su:
                robot.JunctionAction(Robot::LEFT);
                break;
            case P2Su:
                robot.JunctionAction(Robot::RIGHT);
                break;
            case P1Sr:
            case P2Sl:
                robot.JunctionAction(Robot::STRAIGHT);
                break;
            default:
                break;
        }
        robot.FollowLine();
    }

    else if (node==SlP1 || node== SrP2)
    {
        robot.FollowLine();
    }

    else if (node == SuDl || node == SuDr)
    {
        // follow up to turntable
        robot.FollowLine();

        // turn at turntable
        switch (node)
        {
            case SuDl:
                robot.TurntableAction(Robot::LEFT);
                break;
            case SuDr:
                robot.TurntableAction(Robot::RIGHT);
                break;
            default:
                break;
        }

        // follow up to drop off junction
        robot.FollowLine();
    }

    else if (node == D1D2 || node == D1D3 || node == D2D3 || node == D2D1 || node == D3D1 || node == D3D2 ||
            node == D4D5 || node == D4D6 || node == D5D6 || node == D5D4 || node == D6D4 || node == D6D5  ||
            node == D1Dr || node == D2Dr || node == D3Dr ||
            node == D4Dl || node == D5Dl || node == D6Dl ||
            node == D1S || node == D2S || node == D3S ||
            node == D4S || node == D5S || node == D6S)
    {
        // this only gets past the D junction and as such the DlDr transfer nodes require additional work
        switch(node)
        {

            // turn left cases
            case D1D2: case D2D3: case D3Dr: case D3S:
            case D6D5: case D5D4: case D4Dl: case D4S:
                robot.JunctionAction(Robot::LEFT);
                break;

            // Turn right cases
            case D1Dr: case D1S: case D2D1: case D3D2:
            case D6Dl: case D6S: case D5D6: case D4D5:
                robot.JunctionAction(Robot::RIGHT);
                break;

            // straight on cases
            case D1D3: case D2Dr: case D2S: case D3D1:
            case D6D4: case D5Dl: case D5S: case D4D6:
                robot.JunctionAction(Robot::STRAIGHT);
                break;
            default:
                break;

        }

        // take up to Drop off or turntable junction
        robot.FollowLine();

        //actions after turntable

        // straight on at turntable
        if (node == D1Dr || node == D2Dr || node == D3Dr || node == D4Dl || node == D5Dl || node == D6Dl)
        {
            robot.TurntableAction(Robot::STRAIGHT);
        }

        // right at turntable
        else if (node == D1S || node == D2S || node == D3S)
        {
            robot.TurntableAction(Robot::RIGHT);
        }

        // left at turntable
        else if (node == D4S || node == D5S || node == D6S)
        {
            robot.TurntableAction(Robot::LEFT);
        }

        // follow across to D junction or down to S junction
        robot.FollowLine();
    }

    else if(node == SSd || node == SSl || node == SSr)
    {
        // takes robot from after turntable to starting positions

        // pass first junction
        robot.FollowLine();

        switch (node)
        {
            case SSd:
                robot.JunctionAction(Robot::STRAIGHT);
                break;
            case SSr:
                robot.JunctionAction(Robot::LEFT);
                break;
            case SSl:
                robot.JunctionAction(Robot::RIGHT);
                break;
            default:
                break;
        }

        // go to edge of bounding box
        robot.FollowLine();
    }
}

MotionControl::Node MotionControl::GetDropOff(MotionControl::box_type box)
{
    return box_dests[box];
}

MotionControl::box_type MotionControl::IdentifyBox(int num_boxes) {
    return open;
}
