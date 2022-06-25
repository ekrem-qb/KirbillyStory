#pragma once

#include "ConstraintExtension.generated.h"

UCLASS()
class UFConstraintExtension final : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Physics|Components|PhysicsConstraint")
	static void SetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName,
	                                        const FRotator TargetRotator);
private:
	UFConstraintExtension()
	{
	};
};
