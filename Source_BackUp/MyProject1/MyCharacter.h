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
	//添加生命值
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Character")
		float Health = 100;

	//添加isDead布尔值
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "My Character")
		bool isDead = false;

	//死亡计算函数
	virtual void CalculateDead();

	//生命值计算函数
	UFUNCTION(BlueprintCallable, Category = "My Character")
		virtual void CalculateHealth(float Delta);

#if WITH_EDITOR
	//编辑器中修改属性
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
