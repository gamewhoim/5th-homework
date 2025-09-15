#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Previouslocation = FVector2D(0, 0);
	Currentlocation = FVector2D(0, 0);
	TotalDistance = 0.f;
	TotalEventCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("initial Location: (%f, %f)"), Currentlocation.X, Currentlocation.Y);
	move(10, 50);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::move(int32 MoveCount, float Probability)
{
	for (int32 i = 0; i < MoveCount; ++i)
	{
		Previouslocation = Currentlocation;
		Currentlocation.X += Step();
		Currentlocation.Y += Step();
		TriggerEventWithProbability(Probability);
		
		float MoveDistance = Distance(Currentlocation, Previouslocation);
		TotalDistance += MoveDistance;
		UE_LOG(LogTemp, Warning, TEXT("Step %d Location:(%.0f, %.0f), MoveDistance: %.2f"), i + 1, Currentlocation.X, Currentlocation.Y, MoveDistance);
	}
	UE_LOG(LogTemp, Warning, TEXT("TotalDistance: %.2f, TotalEventCount: %d"), TotalDistance, TotalEventCount);

}



void AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Occurred"));
		++TotalEventCount;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Not Occurred"));
	}
}

float AMyActor::Distance(FVector2D second, FVector2D first)
{
	float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(FMath::Square(dx) + FMath::Square(dy));
}
