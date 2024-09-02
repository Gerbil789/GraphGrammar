#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GraphGrammar/Core/Components/GraphGeneratorComponent.h"
#include "GraphGrammar/Core/Components/GraphRendererComponent.h"
#include "GraphGrammarGenerator.generated.h"

UCLASS()
class GRAPHGRAMMAR_API AGraphGrammarGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AGraphGrammarGenerator();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UGraphGeneratorComponent* GraphGenerator;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UGraphRendererComponent* GraphRenderer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Graph")
	UGraph* Graph;

	//---------------------------------

	UFUNCTION(BlueprintCallable, Category = "GraphGrammar")
	void ResetGraph();

};
