#include "GraphRendererComponent.h"
#include "DrawDebugHelpers.h" 

UGraphRendererComponent::UGraphRendererComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGraphRendererComponent::SetGraph(UGraph* InGraph)
{
	Graph = InGraph;
	UE_LOG(LogTemp, Warning, TEXT("RENDERER: Graph set"));
}

void UGraphRendererComponent::RenderGraph()
{
	if (!Graph)
	{
		UE_LOG(LogTemp, Warning, TEXT("No graph to render"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Rendering graph"));
	RenderNodes();
	RenderEdges();
}


void UGraphRendererComponent::ClearDebugShapes()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Clear the previously rendered debug spheres
	for (const FVector& Location : DebugNodeLocations)
	{
		// Draw with 0 duration to effectively clear them
		DrawDebugSphere(World, Location, 20.0f, 12, FColor::Green, false, 0.0f, 0, 2.0f);
	}

	// Clear the previously rendered debug lines
	for (const TPair<FVector, FVector>& Edge : DebugEdgeLocations)
	{
		// Draw with 0 duration to effectively clear them
		DrawDebugLine(World, Edge.Key, Edge.Value, FColor::Blue, false, 0.0f, 0, 2.0f);
	}

	// Clear the tracking arrays
	DebugNodeLocations.Empty();
	DebugEdgeLocations.Empty();
}

void UGraphRendererComponent::RenderNodes()
{
	UE_LOG(LogTemp, Warning, TEXT("Rendering nodes"));

	for (UGraphNode* Node : Graph->Nodes)
	{
		if (Node)
		{
			FVector Location(Node->Position, 0.0f); // Convert 2D position to 3D
			DebugNodeLocations.Add(Location);
			DrawDebugSphere(GetWorld(), Location, 20.0f, 12, FColor::Green, true, -1.0f, 0, 2.0f);
		}
	}
}

void UGraphRendererComponent::RenderEdges()
{
	UE_LOG(LogTemp, Warning, TEXT("Rendering edges"));

	for (UGraphEdge* Edge : Graph->Edges)
	{
		if (Edge)
		{
			FVector Start(Edge->NodeA->Position, 0.0f);
			FVector End(Edge->NodeB->Position, 0.0f);
			DebugEdgeLocations.Add(TPair<FVector, FVector>(Start, End));
			DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, -1.0f, 0, 2.0f);
		}
	}

}
