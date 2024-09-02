#pragma once

#include "CoreMinimal.h"
#include "GraphGrammar/Core/GraphNode.h"
#include "UObject/NoExportTypes.h"
#include "GraphEdge.generated.h"


UCLASS(BlueprintType, Blueprintable)
class GRAPHGRAMMAR_API UGraphEdge : public UObject
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UGraphNode* NodeA;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UGraphNode* NodeB;

    UFUNCTION(BlueprintCallable, Category = "Graph")
    static UGraphEdge* CreateGraphEdge(UGraphNode* InNodeA, UGraphNode* InNodeB);
};
