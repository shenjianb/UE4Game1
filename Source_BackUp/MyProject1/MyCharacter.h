// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS(Blueprintable)
class MYPROJECT1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//�������ֵ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Character")
		float Health = 100;

	//���isDead����ֵ
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "My Character")
		bool isDead = false;

	//�������㺯��
	virtual void CalculateDead();

	//����ֵ���㺯��
	UFUNCTION(BlueprintCallable, Category = "My Character")
		virtual void CalculateHealth(float Delta);

#if WITH_EDITOR
	//�༭�����޸�����
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)override;
#endif

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
