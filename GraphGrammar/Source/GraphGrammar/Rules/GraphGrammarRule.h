#pragma once

#include "CoreMinimal.h"
#include "GraphGrammar/Core/Graph.h"
#include "UObject/NoExportTypes.h"
#include "GraphGrammarRule.generated.h"

UCLASS(Abstract)
class GRAPHGRAMMAR_API UGraphGrammarRule : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Graph Grammar")
	virtual bool ApplyRule(UGraph* Graph) PURE_VIRTUAL(UGraphGrammarRule::ApplyRule, return false;);
};
