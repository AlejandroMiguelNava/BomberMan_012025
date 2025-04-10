// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueFuego.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueFuego() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueFuego();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueFuego_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueFuego
void ABloqueFuego::StaticRegisterNativesABloqueFuego()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueFuego);
UClass* Z_Construct_UClass_ABloqueFuego_NoRegister()
{
	return ABloqueFuego::StaticClass();
}
struct Z_Construct_UClass_ABloqueFuego_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueFuego.h" },
		{ "ModuleRelativePath", "BloqueFuego.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueFuego>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueFuego_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueFuego_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueFuego_Statics::ClassParams = {
	&ABloqueFuego::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueFuego_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueFuego_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueFuego()
{
	if (!Z_Registration_Info_UClass_ABloqueFuego.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueFuego.OuterSingleton, Z_Construct_UClass_ABloqueFuego_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueFuego.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueFuego>()
{
	return ABloqueFuego::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueFuego);
ABloqueFuego::~ABloqueFuego() {}
// End Class ABloqueFuego

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueFuego_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueFuego, ABloqueFuego::StaticClass, TEXT("ABloqueFuego"), &Z_Registration_Info_UClass_ABloqueFuego, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueFuego), 1298574399U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueFuego_h_1196960175(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueFuego_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueFuego_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
