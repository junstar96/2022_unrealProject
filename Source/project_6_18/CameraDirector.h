// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class PROJECT_6_18_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = Camera)
	void CameraSwitch(int CameraNum);

	UFUNCTION(BlueprintCallable, Category = Camera)
		void BrokenWathing();

	UFUNCTION(BlueprintCallable, Category = Camera)
		void EndCameraShow();

	UPROPERTY(EditAnywhere)
		AActor* camera1;

	UPROPERTY(EditAnywhere)
		AActor* camera2;

	UPROPERTY(EditAnywhere)
		AActor* ObjectBrokenCamera;

	UPROPERTY(EditAnywhere)
		AActor* gameEndCamera;

	float timetonextcameraswitch;



};
