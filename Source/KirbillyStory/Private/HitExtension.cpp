// Fill out your copyright notice in the Description page of Project Settings.


#include "HitExtension.h"

void UHitExtension::GetMyBoneName(const FHitResult& Hit, FName& MyBoneName)
{
	MyBoneName = Hit.MyBoneName;
}
