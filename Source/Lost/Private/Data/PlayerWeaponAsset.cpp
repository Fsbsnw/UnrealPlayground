// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/PlayerWeaponAsset.h"

FPlayerWeapon UPlayerWeaponAsset::GetWeaponByLevel(int32 Level)
{
	int32 Index = Level - 1;

	if (PlayerWeapons.IsValidIndex(Index))
	{
		return PlayerWeapons[Index];
	}
	return PlayerWeapons.Last();
}