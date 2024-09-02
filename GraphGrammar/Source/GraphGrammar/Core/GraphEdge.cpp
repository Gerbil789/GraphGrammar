#include "GraphEdge.h"

UGraphEdge* UGraphEdge::CreateGraphEdge(UGraphNode* InNodeA, UGraphNode* InNodeB)
{
    UGraphEdge* NewEdge = NewObject<UGraphEdge>();
    NewEdge->NodeA = InNodeA;
    NewEdge->NodeB = InNodeB;
    UE_LOG(LogTemp, Warning, TEXT("Created Edge between Node ID: %d and Node ID: %d"), NewEdge->NodeA->Id, NewEdge->NodeB->Id);
    return NewEdge;
}
