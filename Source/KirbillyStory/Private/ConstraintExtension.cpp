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

void UFConstraintExtension::SetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName,
                                                          const float Stiffness)
{
	FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		const FConstraintDrive PreviousDriveParams = Joint->ProfileInstance.AngularDrive.SlerpDrive;
		Joint->SetAngularDriveParams(Stiffness, PreviousDriveParams.Damping, PreviousDriveParams.MaxForce);
	}
}

float UFConstraintExtension::GetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName)
{
	const FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		return Joint->ProfileInstance.AngularDrive.SlerpDrive.Stiffness;
	}
	return 0;
}
