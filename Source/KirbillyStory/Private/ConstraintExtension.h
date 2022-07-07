#pragma once

#include "PhysicsEngine/PhysicsConstraintComponent.h"

#include "ConstraintExtension.generated.h"

UCLASS()
class UConstraintExtension final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint")
	static void SetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName,
	                                        const FRotator TargetRotator);

	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint", BlueprintPure)
	static FQuat GetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName);

	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint", BlueprintPure)
	static FRotator GetAngularOrientationTarget(UPhysicsConstraintComponent* Constraint);

	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint", BlueprintPure)
	static void GetConstrainedComponents(const UPhysicsConstraintComponent* Constraint, UPrimitiveComponent*& Component1, FName& BoneName1, UPrimitiveComponent*& Component2, FName& BoneName2);

	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint")
	static void SetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName,
	                                          const float Stiffness);

	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint", BlueprintPure)
	static float GetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName);
private:
	UConstraintExtension()
	{
	};
};
