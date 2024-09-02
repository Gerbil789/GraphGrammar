#include "GraphNode.h"

int UGraphNode::NextId = 0;

UGraphNode* UGraphNode::CreateGraphNode(FVector2D InPosition)
{
    UGraphNode* NewNode = NewObject<UGraphNode>();
	NewNode->Position = InPosition;
	NewNode->Id = ++NextId;
	UE_LOG(LogTemp, Warning, TEXT("Created Node ID: %d, Position: (%f, %f)"), NewNode->Id, NewNode->Position.X, NewNode->Position.Y);
	return NewNode;
}
