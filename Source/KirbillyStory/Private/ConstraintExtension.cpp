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

FQuat UFConstraintExtension::GetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName)
{
	const FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		return FQuat(Joint->ProfileInstance.AngularDrive.OrientationTarget);
	}
	return FQuat::MakeFromEuler(FVector(180, 180, 180));
}
