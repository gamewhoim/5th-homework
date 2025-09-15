#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class A24_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//기능구현 맴버함수
	FVector2D Previouslocation;
	FVector2D Currentlocation; //현재위치
	
	float TotalDistance;
	int32 TotalEventCount;
	

	int32 Step();
	void move(int32 MoveCount, float Probability);
	void TriggerEventWithProbability(float Probability);
	float Distance(FVector2D second, FVector2D first);
};
