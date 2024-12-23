#include <iostream>
#include <unordered_set>
#include "Graph.h"
#include "Stack.h"

void dfs(const Graph &graph, const std::string &startNode)
{
    Stack<std::string> stack;
    std::unordered_set<std::string> visited;

    stack.push(startNode);

    while (!stack.isEmpty())
    {
        std::string currentNode = stack.pop();
        if (visited.find(currentNode) == visited.end())
        {
            std::cout << currentNode << " ";
            visited.insert(currentNode);

            for (const auto &neighbor : graph.getNeighbors(currentNode))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    stack.push(neighbor);
                }
            }
        }
    }
}

void bfs(const Graph &graph, const std::string &startNode)
{
    Stack<std::string> leftStack;
    Stack<std::string> rightStack;
    std::unordered_set<std::string> visited;

    leftStack.push(startNode);
    visited.insert(startNode);

    while (!leftStack.isEmpty() || !rightStack.isEmpty())
    {
        while (!leftStack.isEmpty())
        {
            std::string currentNode = leftStack.pop();
            std::cout << currentNode << " ";

            for (const auto &neighbor : graph.getNeighbors(currentNode))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    rightStack.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        while (!rightStack.isEmpty())
        {
            std::string currentNode = rightStack.pop();
            std::cout << currentNode << " ";

            for (const auto &neighbor : graph.getNeighbors(currentNode))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    leftStack.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
}

int main()
{
    Graph graph;

    graph.addNodes({"A", "B","C","D","E","F","G"});
    graph.linkMany("A", {"B","C","F"});
    graph.linkMany("B", {"D","E"});
    graph.link("F", "G");
    graph.printGraph();

    std::cout << "DFS:" << std::endl;
    dfs(graph, "A");

    std::cout << "\nBFS:" << std::endl;
    bfs(graph, "A");

    return 0;
}