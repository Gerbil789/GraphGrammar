#include "GraphGeneratorComponent.h"
#include "GraphGrammar/Rules/TestGraphGrammarRule.h"
#include "GraphGrammar/Rules/AddEdge.h"

UGraphGeneratorComponent::UGraphGeneratorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGraphGeneratorComponent::SetGraph(UGraph* InGraph)
{
	Graph = InGraph;
	UE_LOG(LogTemp, Warning, TEXT("GENERATOR: Graph set"));
}


void UGraphGeneratorComponent::LoadRules()
{
	UE_LOG(LogTemp, Warning, TEXT("Loading rules"));
	Rules.Empty();

	Rules.Add(NewObject<UTestGraphGrammarRule>());
	Rules.Add(NewObject<UAddEdge>());

	UE_LOG(LogTemp, Warning, TEXT("Rules:"));
	for (int32 i = 0; i < Rules.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Rule %d: %s"), i, *Rules[i]->GetName());
	}
}

void UGraphGeneratorComponent::ApplyRandomRule()
{
	if (!Graph)
	{
		UE_LOG(LogTemp, Warning, TEXT("No graph to apply rules to"));
		return;
	}

	if (Rules.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No rules to apply"));
		return;
	}

	int32 RandomIndex = FMath::RandRange(0, Rules.Num() - 1);
	UGraphGrammarRule* RandomRule = Rules[RandomIndex];
	if (!RandomRule)
	{
		UE_LOG(LogTemp, Warning, TEXT("Random rule was nullptr"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Applying rule %s"), *RandomRule->GetName());

	if (!RandomRule->ApplyRule(Graph))
	{
		UE_LOG(LogTemp, Warning, TEXT("Rule application failed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Rule applied successfully"));
	}
}


