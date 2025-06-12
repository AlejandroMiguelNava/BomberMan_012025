// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaCompuesta.h"

void ATrampaCompuesta::AgregarTrampa(ATrampas* Trampa)
{
	Trampas.Add(Trampa);
}

void ATrampaCompuesta::ActivarTrampa()
{
	for (ATrampas* Trampa : Trampas)
	{
		if (Trampa) Trampa->ActivarTrampa();
	}
}

void ATrampaCompuesta::DaniarJugador()
{
	for (ATrampas* Trampa : Trampas)
	{
		if (Trampa) Trampa->DaniarJugador();
	}
}