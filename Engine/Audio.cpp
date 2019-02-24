#include "pch.h"

#include "Audio.h"
#include "../Audio/WAVFileReader.h"

void Engine::Audio::Init(File_system *FS)
{
	this->FS = FS;

	AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;

#ifdef _DEBUG
	eflags = eflags | AudioEngine_Debug;
#endif

	audEngine = make_unique<AudioEngine>(eflags);
	if (!audEngine.operator bool())
	{
		DebugTrace("Sound_system: Error audEngine = make_unique.\n");
		throw exception("audEngine == nullptr!!!");
		InitSoundSystem = false;
	}
	InitSoundSystem = true;
}

void Engine::Audio::AddNewSound()
{
	ListSoundsFile = FS->getFilesInFolder(&wstring(L"Sounds"), false, false);
	for (int i = 0; i < ListSoundsFile.size(); i++)
	{
		soundEffect[i] = make_unique<SoundEffect>(audEngine.get(), ListSoundsFile.at(i).c_str());

		sound.push_back(soundEffect[i]->CreateInstance());
		if (!sound.at(i))
		{
			DebugTrace("Sound_system: Error sound.push_back.\n");
			throw exception("sound[i] == null!!!");
		}
	}
}

void Engine::Audio::Update()
{
	if (!audEngine->Update())
	{
		if (audEngine->IsCriticalError())
		{
			DebugTrace("Sound_system: Error IsCriticalError.\n");
			throw exception("audEngine: has critical errors with audio!");
		}
	}
}

void Engine::Audio::doPlay()
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->Play(true);
}

void Engine::Audio::changeSoundVol(float Vol)
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->SetVolume(Vol);
}

void Engine::Audio::changeSoundPan(float Pan)
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->SetPan(Pan);
}

void Engine::Audio::doPause()
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->Pause();
}

void Engine::Audio::doResume()
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->Resume();
}

void Engine::Audio::doStop()
{
	for (int i = 0; i < sound.size(); i++)
		sound.at(i)->Stop();
}
