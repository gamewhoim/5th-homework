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
	//��ɱ��� �ɹ��Լ�
	FVector2D Previouslocation;
	FVector2D Currentlocation; //������ġ
	
	float Totaldistance;
	int32 Totaleventcount;
	

	int32 Step();
	void move(int32 MoveCount);
	void TriggerEventWithProbability(float Probability);
	float distance(FVector second, FVector first)
	{
		float dx = first.X - second.X;
		float dy = first.Y - second.Y;
		return FMath::Sqrt(dx * dx + dy * dy);
	}

};


{

}
