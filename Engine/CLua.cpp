#include "pch.h"
#define SOL_CHECK_ARGUMENTS 1

#include "CLua.h"

ToDo("It's Necessary To Add Catch Some Errors!");

class Engine;
extern shared_ptr<Engine> Application;
#include "Engine.h"
#include "File_system.h"
#include "Console.h"

void CLua::GetDate(string Text)
{
	MessageBoxA(Application->GetHWND(), Text.c_str(), "DecisionSolver", MB_OK);
}

void CLua::Init()
{
	LuaState.open_libraries();

	auto bark = LuaState["Engine"].get_or_create<table>();
	bark.new_usertype<Console>("Console", "AddCmd", &Console::AddCmd);
}

void CLua::Update()
{
	try
	{
		LuaState.script_file(Application->getFS()->GetFile("test.lua")->PathA);
	}
	catch (const exception &SomeError)
	{
		if (MessageBoxA(Application->GetHWND(), string(string("Some errors with LUA:\n") + SomeError.what() + 
			string("\nDo you want to continue?")).c_str(), Application->getNameWndA().c_str(), MB_YESNO) == IDYES)
		{
			Application->getUI()->getDialog("Console")->getChilds().back()->getUTexts().back()->AddCLText(
				UnformatedText::Type::Error, string("Some errors with LUA:\n") + SomeError.what());

			return;
		}
	}
}

void CLua::callFunction(string FileName, string Function, string params)
{
	try
	{
		auto File = Application->getFS()->GetFile(FileName)->PathA;
		if (File.empty())
		{
			Application->getUI()->getDialog("Console")->getChilds().back()->getUTexts().back()->AddCLText(
				UnformatedText::Type::Error, string("Lua error: File: \"") + FileName + string("\" Doesn't Exist!"));

			return;
		}
		LuaState.load_file(File);
		LuaState.get<sol::function>(Function.c_str()).template call<void>(params);
	}
	catch (error e)
	{
		Application->getUI()->getDialog("Console")->getChilds().back()->getUTexts().back()->AddCLText(
			UnformatedText::Type::Error, string("Lua error:\n") + string(e.what()));
		printf("Lua error: %s", e.what());
	}
}
