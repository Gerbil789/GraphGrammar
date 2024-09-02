#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GraphGrammar/Core/Graph.h"
#include "GraphRendererComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRAPHGRAMMAR_API UGraphRendererComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGraphRendererComponent();


	//---------------------------------

	UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
	void SetGraph(UGraph* InGraph);

	UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
	void RenderGraph();

	UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
	void ClearDebugShapes();

private:
	UGraph* Graph;


	void RenderNodes();
	void RenderEdges();

	TArray<FVector> DebugNodeLocations;
	TArray<TPair<FVector, FVector>> DebugEdgeLocations;

};
