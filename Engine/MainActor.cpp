#include "pch.h"

#include "MainActor.h"

void Engine::MainActor::Update()
{
	if (Health == 0.0f & !IsGod)
		IsDead = true;
	else if (IsGod)
		Health = 999999.9999f;

	Position = gCamera->GetEyePt();

	float fAspectRatio = DXUTGetDXGIBackBufferSurfaceDesc()->Width / (FLOAT)DXUTGetDXGIBackBufferSurfaceDesc()->Height;
	gCamera->SetProjParams(gCamera->getFOV(), fAspectRatio, 0.1f, 1000.0f);
}

void Engine::MainActor::Render(Matrix View, Matrix Proj)
{
	Update();
}

void Engine::MainActor::Destroy()
{}