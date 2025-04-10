// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueSline.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueSline() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueSline();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueSline_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueSline
void ABloqueSline::StaticRegisterNativesABloqueSline()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueSline);
UClass* Z_Construct_UClass_ABloqueSline_NoRegister()
{
	return ABloqueSline::StaticClass();
}
struct Z_Construct_UClass_ABloqueSline_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueSline.h" },
		{ "ModuleRelativePath", "BloqueSline.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueSline>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueSline_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueSline_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueSline_Statics::ClassParams = {
	&ABloqueSline::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueSline_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueSline_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueSline()
{
	if (!Z_Registration_Info_UClass_ABloqueSline.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueSline.OuterSingleton, Z_Construct_UClass_ABloqueSline_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueSline.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueSline>()
{
	return ABloqueSline::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueSline);
ABloqueSline::~ABloqueSline() {}
// End Class ABloqueSline

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueSline_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueSline, ABloqueSline::StaticClass, TEXT("ABloqueSline"), &Z_Registration_Info_UClass_ABloqueSline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueSline), 2971090752U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueSline_h_2238215929(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueSline_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_BloqueSline_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
