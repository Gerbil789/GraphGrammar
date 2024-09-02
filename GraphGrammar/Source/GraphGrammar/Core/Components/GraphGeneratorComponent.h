#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GraphGrammar/Rules/GraphGrammarRule.h"
#include "GraphGeneratorComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRAPHGRAMMAR_API UGraphGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGraphGeneratorComponent();
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphGrammar")
    TArray<UGraphGrammarRule*> Rules;

    //---------------------------------

    UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
    void SetGraph(UGraph* InGraph);

    UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
    void LoadRules();

    UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
    void ApplyRandomRule();

private:
    UGraph* Graph;
};
