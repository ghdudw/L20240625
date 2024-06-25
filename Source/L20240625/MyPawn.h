// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UFloatingPawnMovement;
class USpringArmComponent;
class UCameraComponent;



UCLASS()
class L20240625_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Components")
	TObjectPtr <UBoxComponent> Box;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UStaticMeshComponent> Body;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UStaticMeshComponent> Left;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UStaticMeshComponent> Right;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UArrowComponent> Arrow;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UCameraComponent> Camera;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr <UFloatingPawnMovement> Movemont;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Status")
	float Booster;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Status")
	TSubclassOf<class AMyRocket> RocketTemplate;

	void Pitch(float Value);
	void Roll(float Value);
	void PressBooster();
	void ReleaseBooster();

	UFUNCTION(BlueprintNativeEvent)
	void BPCallCPPOverride(int Score);
	void BPCallCPPOverride_Implementation(int Score);


	//C++ call Blueprint function execute, ��Ʈ, ��ȹ�ڴ� ���α׷����� ���� �ȵ�
	UFUNCTION(BlueprintImplementableEvent)
	void BPCallCPP(int Score);

	//Blueprint call C++ function execute
	UFUNCTION(BlueprintCallable)
	void Fire();
};
