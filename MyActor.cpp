#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Currentlocation = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("initial Location: (%f, %f)"), Currentlocation.X, Currentlocation.Y);
	move(10);
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

void AMyActor::move(int32 MoveCount)
{
	for (int32 i = 0; i < MoveCount; ++i)
	{
		Currentlocation.X += Step();
		Currentlocation.Y += Step();
		UE_LOG(LogTemp, Warning, TEXT("Step %d Location:: (%f, %f)"), i + 1, Currentlocation.X, Currentlocation.Y);

	}
}
