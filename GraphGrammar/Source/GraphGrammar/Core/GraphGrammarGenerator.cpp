#include "GraphGrammarGenerator.h"

AGraphGrammarGenerator::AGraphGrammarGenerator()
{
	PrimaryActorTick.bCanEverTick = true;

	GraphGenerator = CreateDefaultSubobject<UGraphGeneratorComponent>(TEXT("GraphGenerator"));
	GraphRenderer = CreateDefaultSubobject<UGraphRendererComponent>(TEXT("GraphRenderer"));

	ResetGraph();
}

void AGraphGrammarGenerator::ResetGraph()
{
	Graph = UGraph::CreateGraph();
	UE_LOG(LogTemp, Warning, TEXT("Graph reset"));

	GraphGenerator->SetGraph(Graph);
	GraphRenderer->SetGraph(Graph);
}
