#include "pch.h"
#include "Dialogs.h"

class Engine;
extern shared_ptr<Engine> Application;
#include "Engine.h"

HRESULT Dialogs::Init()
{
	doc = make_shared<tinyxml2::XMLDocument>();
	if (!doc.operator bool())
	{
		throw exception("Dialogs->Init()::doc == nullptr!!!");
		InitClass = false;
		return E_FAIL;
	}

	InitClass = true;
	return S_OK;
}

HRESULT Dialogs::LoadFile(string *FileName)
{
	doc->LoadFile(Application->getFS()->GetFile(*FileName)->PathA.c_str());
	if (doc->ErrorID() > 0)
	{
		Engine::StackTrace(doc->ErrorStr());
		throw exception(string(string("Dialogs->LoadFile()::doc->LoadFile:\n") + string(doc->ErrorStr())).c_str());
		return E_FAIL;
	}
	if (doc->Parse(Application->getFS()->getDataFromFile(FileName, false).c_str()) > 0)
	{
		throw exception(string(string("Dialogs->LoadFile()::doc->Parse:\n") + string(doc->ErrorStr())).c_str());
		return E_FAIL;
	}

	return S_OK;
}

void Dialogs::getReplices()
{
	auto Main_Element = doc->RootElement();
	if (!Main_Element)
	{
		DebugTrace("Dialogs->getReplices()::doc->RootElement() == nullptr!!!");
		throw exception("Dialogs->getReplices()::doc->RootElement() == nullptr!!!");
		return;
	}
	for (;;)
	{
		if (Replices.empty())
		{
			Nodes.push_back(Main_Element->FirstChild());
			Replices.push_back(Nodes.back()->FirstChild()->Value());
			continue;
		}

		Nodes.push_back(Nodes.back()->NextSibling());
		Replices.push_back(Nodes.back()->FirstChild()->Value());

		if (Main_Element->LastChild()->FirstChild()->Value() == Nodes.back()->FirstChild()->Value())
			break;
	}
}
