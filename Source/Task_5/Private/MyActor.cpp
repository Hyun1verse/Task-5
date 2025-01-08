#include "MyActor.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;	// Tick 활성화
	mStart = FVector2d(0.0f, 0.0f);	// 시작점 초기화
}

// 게임이 시작되거나 스폰될 때 호출
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	MoveActor();	// 이동 로직 실행
}

// 매 프레임 호출
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::CalculateStep()
{
	return FMath::RandRange(0, 1);	// 0 또는 1 반환
}

void AMyActor::MoveActor()
{
	for (int32 i = 0; i < 10; ++i)
	{
		// 각 좌표에서 랜덤으로 이동 거리 계산
		int32 stepX = CalculateStep();
		int32 stepY = CalculateStep();

		// 이동 제한: x, y 각각 2 미만이어야 함
		if (stepX >= 2 || stepY >= 2)
		{
			continue;	// 조건에 맞지 않으면 건너뜀
		}

		// 좌표 업데이트
		mStart.X += stepX;
		mStart.Y += stepY;

		// 로그 출력
		UE_LOG(LogTemp, Warning, TEXT("Current Position: (%f %f)"), mStart.X, mStart.Y);
	}
}
