#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GraphNode.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GRAPHGRAMMAR_API UGraphNode : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Position;

	UFUNCTION(BlueprintCallable, Category = "Graph")
	static UGraphNode* CreateGraphNode(FVector2D InPosition);
private:
	static int NextId;
};
