#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

class Graph
{
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
public:
    void addNode(const std::string &name)
    {
        adjList[name] = std::unordered_set<std::string>();
    }

    void link(const std::string &from, const std::string &to)
    {
        adjList[from].insert(to);
        adjList[to].insert(from);
    }

    std::unordered_set<std::string> getNeighbors(const std::string &node) const
    {
        auto it = adjList.find(node);
        if (it != adjList.end())
        {
            return it->second;
        }
        return {};
    }

    void printGraph() const
    {
        for (const auto &pair : adjList)
        {
            std::cout << pair.first << " -> ";
            for (const auto &neighbor : pair.second)
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
    
};

#endif