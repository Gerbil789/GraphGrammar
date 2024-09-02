#include "TestGraphGrammarRule.h"

bool UTestGraphGrammarRule::ApplyRule(UGraph* Graph)
{
    // Example: Find an edge and split it into two by adding a node in the middle
    if (!Graph->Edges.IsEmpty())
    {
        UGraphEdge* Edge = Graph->Edges[FMath::RandRange(0, Graph->Edges.Num() - 1)];
        FVector2D Midpoint = (Edge->NodeA->Position + Edge->NodeB->Position) / 2.0f;

        UGraphNode* NewNode = UGraphNode::CreateGraphNode(Midpoint);
        Graph->Nodes.Add(NewNode);

        Graph->Edges.Remove(Edge);
        Graph->AddEdge(Edge->NodeA, NewNode);
        Graph->AddEdge(NewNode, Edge->NodeB);

        UE_LOG(LogTemp, Warning, TEXT("Applied Rule: Split Edge between Node ID: %d and Node ID: %d"), Edge->NodeA->Id, Edge->NodeB->Id);
        UE_LOG(LogTemp, Warning, TEXT("New Node ID: %d, Position: (%f, %f)"), NewNode->Id, NewNode->Position.X, NewNode->Position.Y);

        return true; // Rule applied
    }

    return false; // Rule not applicable
}
