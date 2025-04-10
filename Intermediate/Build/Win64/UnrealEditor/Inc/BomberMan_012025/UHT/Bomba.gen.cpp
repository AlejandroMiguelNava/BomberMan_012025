// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Bomba.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBomba() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABomba();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABomba_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABomba
void ABomba::StaticRegisterNativesABomba()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABomba);
UClass* Z_Construct_UClass_ABomba_NoRegister()
{
	return ABomba::StaticClass();
}
struct Z_Construct_UClass_ABomba_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Bomba.h" },
		{ "ModuleRelativePath", "Bomba.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MallaBomba_MetaData[] = {
		{ "Category", "Componentes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Componente de malla est\xef\xbf\xbdtica\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Bomba.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Componente de malla est\xef\xbf\xbdtica" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RadioExplosion_MetaData[] = {
		{ "Category", "Bomba" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Radio de explosi\xef\xbf\xbdn\n" },
#endif
		{ "ModuleRelativePath", "Bomba.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Radio de explosi\xef\xbf\xbdn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TiempoDetonacion_MetaData[] = {
		{ "Category", "Bomba" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tiempo para detonar la bomba\n" },
#endif
		{ "ModuleRelativePath", "Bomba.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tiempo para detonar la bomba" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bloques_MetaData[] = {
		{ "Category", "Bomba" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Referencias a los objetos en el mundo\n" },
#endif
		{ "ModuleRelativePath", "Bomba.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Referencias a los objetos en el mundo" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Enemigos_MetaData[] = {
		{ "Category", "Bomba" },
		{ "ModuleRelativePath", "Bomba.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MallaBomba;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RadioExplosion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TiempoDetonacion;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Bloques_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Bloques;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Enemigos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Enemigos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABomba>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_MallaBomba = { "MallaBomba", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABomba, MallaBomba), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MallaBomba_MetaData), NewProp_MallaBomba_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_RadioExplosion = { "RadioExplosion", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABomba, RadioExplosion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RadioExplosion_MetaData), NewProp_RadioExplosion_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_TiempoDetonacion = { "TiempoDetonacion", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABomba, TiempoDetonacion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TiempoDetonacion_MetaData), NewProp_TiempoDetonacion_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_Bloques_Inner = { "Bloques", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ABloque_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_Bloques = { "Bloques", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABomba, Bloques), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bloques_MetaData), NewProp_Bloques_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_Enemigos_Inner = { "Enemigos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AEnemigo_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_Enemigos = { "Enemigos", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABomba, Enemigos), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Enemigos_MetaData), NewProp_Enemigos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABomba_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_MallaBomba,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_RadioExplosion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_TiempoDetonacion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_Bloques_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_Bloques,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_Enemigos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_Enemigos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABomba_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABomba_Statics::ClassParams = {
	&ABomba::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABomba_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::Class_MetaDataParams), Z_Construct_UClass_ABomba_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABomba()
{
	if (!Z_Registration_Info_UClass_ABomba.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABomba.OuterSingleton, Z_Construct_UClass_ABomba_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABomba.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABomba>()
{
	return ABomba::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABomba);
ABomba::~ABomba() {}
// End Class ABomba

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Bomba_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABomba, ABomba::StaticClass, TEXT("ABomba"), &Z_Registration_Info_UClass_ABomba, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABomba), 709425098U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Bomba_h_4213177858(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Bomba_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Info_Computers_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Bomba_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
