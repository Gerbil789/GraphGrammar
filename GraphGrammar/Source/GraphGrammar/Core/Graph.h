#pragma once

#include "CoreMinimal.h"
#include "GraphGrammar/Core/GraphNode.h"
#include "GraphGrammar/Core/GraphEdge.h"
#include "UObject/NoExportTypes.h"
#include "Graph.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GRAPHGRAMMAR_API UGraph : public UObject
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UGraphNode*> Nodes = TArray<UGraphNode*>();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UGraphEdge*> Edges = TArray<UGraphEdge*>();


    UFUNCTION(BlueprintCallable, Category = "Graph")
    void AddNode(FVector2D Position);

    UFUNCTION(BlueprintCallable, Category = "Graph")
    void AddEdge(UGraphNode* NodeA, UGraphNode* NodeB);

    UFUNCTION(BlueprintCallable, Category = "Graph")
    static UGraph* CreateGraph();
};
