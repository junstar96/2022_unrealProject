// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	const float TimebetweenCameraChanges = 2.0f;
	const float smoothblendtime = 0.75f;

	timetonextcameraswitch -= DeltaTime;

	
}

void ACameraDirector::CameraSwitch(int CameraNum)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);
	

	if (controller)
	{
		if (CameraNum == 1)
		{
			if ((controller->GetViewTarget() != camera1) && (camera1 != nullptr))
			{
				controller->SetViewTarget(camera1);
			}
		}
		else if (CameraNum == 2)
		{
			if ((controller->GetViewTarget() != camera2) && (camera2 != nullptr))
			{
				controller->SetViewTarget(camera2);
			}
		}
	}
}

void ACameraDirector::BrokenWathing()
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);

	if (controller)
	{
		if ((controller->GetViewTarget() != ObjectBrokenCamera) && (ObjectBrokenCamera != nullptr))
		{
			controller->SetViewTargetWithBlend(ObjectBrokenCamera, 3.0f);
		}
	}

}

void ACameraDirector::EndCameraShow()
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);
	if (controller)
	{
		if ((controller->GetViewTarget() != gameEndCamera) && (gameEndCamera != nullptr))
		{
			controller->SetViewTargetWithBlend(gameEndCamera, 1.0f);
			
		}
	}
}

