#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TASK_5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	// 현재 좌표 저장하는 멤버 변수
	FVector2D mStart;
	
	// 게임이 시작되거나 스폰될 때 호출
	virtual void BeginPlay() override;
	

public:	
	//매 프레임 호출
	virtual void Tick(float DeltaTime) override;

	// 좌표를 10번 이동하며 출력
	void MoveActor();

	// 이동 거리를 계산하는 함수
	int32 CalculateStep();
};
