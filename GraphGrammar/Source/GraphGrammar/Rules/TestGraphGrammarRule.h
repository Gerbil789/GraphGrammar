#pragma once

#include "CoreMinimal.h"
#include "GraphGrammar/Rules/GraphGrammarRule.h"
#include "TestGraphGrammarRule.generated.h"


UCLASS(Blueprintable)
class GRAPHGRAMMAR_API UTestGraphGrammarRule : public UGraphGrammarRule
{
	GENERATED_BODY()
public:
	virtual bool ApplyRule(UGraph* Graph) override;
};
