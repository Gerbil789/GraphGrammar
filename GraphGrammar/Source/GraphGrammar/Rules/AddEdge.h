#pragma once

#include "CoreMinimal.h"
#include "GraphGrammar/Rules/GraphGrammarRule.h"
#include "AddEdge.generated.h"

UCLASS()
class GRAPHGRAMMAR_API UAddEdge : public UGraphGrammarRule
{
	GENERATED_BODY()

public:
	virtual bool ApplyRule(UGraph* Graph) override;
};
