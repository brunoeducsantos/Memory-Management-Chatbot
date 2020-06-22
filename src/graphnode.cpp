#include "graphedge.h"
#include "graphnode.h"
#include <memory>
GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()

{       

}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{   
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
_childEdges.push_back(move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(unique_ptr<ChatBot> chatbot)
{
    _chatBot = new ChatBot(*chatbot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(unique_ptr<ChatBot>(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{

    return _childEdges[index].get();

}