#include "ConstraintExtension.h"

void UFConstraintExtension::SetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName,
	const FRotator TargetRotator)
{
	FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		Joint->SetAngularOrientationTarget(TargetRotator.Quaternion());
	}
}
