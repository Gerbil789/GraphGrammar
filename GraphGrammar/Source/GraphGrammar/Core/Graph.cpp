#include "Graph.h"

void UGraph::AddNode(FVector2D Position)
{
	UGraphNode* NewNode = UGraphNode::CreateGraphNode(Position);
	Nodes.Add(NewNode);
}

void UGraph::AddEdge(UGraphNode* NodeA, UGraphNode* NodeB)
{
	UGraphEdge* NewEdge = UGraphEdge::CreateGraphEdge(NodeA, NodeB);
	Edges.Add(NewEdge);
}

UGraph* UGraph::CreateGraph()
{
	UGraph* NewGraph = NewObject<UGraph>();
	return NewGraph;
}
