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
public:
    void addNode(const std::string &name)
    {
        adjacencyList[name] = std::unordered_set<std::string>();
    }

    void connect(const std::string &from, const std::string &to)
    {
        adjacencyList[from].insert(to);
        adjacencyList[to].insert(from);
    }

    std::unordered_set<std::string> getNeighbors(const std::string &node) const
    {
        auto it = adjacencyList.find(node);
        if (it != adjacencyList.end())
        {
            return it->second;
        }
        return {};
    }

    void printGraph() const
    {
        for (const auto &pair : adjacencyList)
        {
            std::cout << pair.first << " -> ";
            for (const auto &neighbor : pair.second)
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;
};

#endif