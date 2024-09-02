#include "AddEdge.h"

bool UAddEdge::ApplyRule(UGraph* Graph)
{
    if (Graph->Nodes.IsEmpty() || Graph->Edges.IsEmpty())
    {
        return false; // Rule not applicable
    }

    UGraphNode* Node = Graph->Nodes[FMath::RandRange(0, Graph->Nodes.Num() - 1)];

    FVector2D NewNodePosition = FVector2D(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500));
    UGraphNode* NewNode = UGraphNode::CreateGraphNode(NewNodePosition);
    Graph->Nodes.Add(NewNode);

    Graph->AddEdge(Node, NewNode);

    UE_LOG(LogTemp, Warning, TEXT("Applied Rule: Add Edge from Node ID: %d to Node ID: %d"), Node->Id, NewNode->Id);

    return true;
}
