#include "ConstraintExtension.h"

void UConstraintExtension::SetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName,
                                                       const FRotator TargetRotator)
{
	FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		Joint->SetAngularOrientationTarget(TargetRotator.Quaternion());
	}
}

FQuat UConstraintExtension::GetConstraintTargetRotation(USkeletalMeshComponent* Mesh, const FName JointName)
{
	const FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		return FQuat(Joint->ProfileInstance.AngularDrive.OrientationTarget);
	}
	return FQuat::MakeFromEuler(FVector(180, 180, 180));
}

FRotator UConstraintExtension::GetAngularOrientationTarget(UPhysicsConstraintComponent* Constraint)
{
	return Constraint->ConstraintInstance.ProfileInstance.AngularDrive.OrientationTarget;
}

void UConstraintExtension::GetConstrainedComponents(const UPhysicsConstraintComponent* Constraint,
	UPrimitiveComponent*& Component1, FName& BoneName1, UPrimitiveComponent*& Component2, FName& BoneName2)
{
	Component1 = Constraint->OverrideComponent1.Get();
	Component2 = Constraint->OverrideComponent2.Get();
	BoneName1 = Constraint->ConstraintInstance.ConstraintBone1;
	BoneName2 = Constraint->ConstraintInstance.ConstraintBone2;
}

void UConstraintExtension::SetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName,
                                                         const float Stiffness)
{
	FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		const FConstraintDrive PreviousDriveParams = Joint->ProfileInstance.AngularDrive.SlerpDrive;
		Joint->SetAngularDriveParams(Stiffness, PreviousDriveParams.Damping, PreviousDriveParams.MaxForce);
	}
}

float UConstraintExtension::GetConstraintAngularStiffness(USkeletalMeshComponent* Mesh, const FName JointName)
{
	const FConstraintInstance* Joint = Mesh->FindConstraintInstance(JointName);
	if (Joint != nullptr)
	{
		return Joint->ProfileInstance.AngularDrive.SlerpDrive.Stiffness;
	}
	return 0;
}
