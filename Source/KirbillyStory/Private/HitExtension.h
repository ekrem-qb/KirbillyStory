#pragma once

#include "HitExtension.generated.h"

UCLASS()
class UHitExtension final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="Collision")
	static void GetMyBoneName(const FHitResult& Hit, FName& MyBoneName);
private:
	UHitExtension()
	{
	}
};
