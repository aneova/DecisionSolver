#include "pch.h"
#include "UI.h"

HRESULT UI::Init()
{
	try
	{
		g_HUD.Init(&g_DialogResourceManager);
		InitUI = true;
		return S_OK;
	}
	catch (const exception ex)
	{
		DebugTrace("UI: Init failed. Line: 12\n");
		throw std::exception("Init == nullptr!!!");
		InitUI = false;
		return E_FAIL;
	}
}

HRESULT UI::AddButton(CDXUTDialog *Dial, int ID, wstring Text, int X, int Y, int W, int H, int Key)
{
	return S_OK;
}

HRESULT UI::AddButton(CDXUTDialog *Dial, int ID, wstring Text, int X, int Y, int W, int H)
{
	return S_OK;
}

HRESULT UI::AddButton(CDXUTDialog *Dial, int ID, wstring Text)
{
	try
	{
		//if (ID->size() != Text.size())
		//{
		//	DebugTrace("UI: AddButton failed. An equal number of ID elements and text is required. Line: 36\n");
		//	throw std::exception("ID.size() != Text.size()!!!");
		//	return E_FAIL;
		//}
		ObjButton.push_back(ID);
		ObjNameButton.push_back(Text);
		Dial->AddButton(ObjButton.back(), ObjNameButton.back().c_str(), 35, iY, 125, 22, VK_F2);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddButton failed. Line: 45\n");
		throw std::exception("AddButton failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddStatic(CDXUTDialog *Dial, int ID, wstring Text, int X, int Y, int W, int H, int Key)
{
	return E_NOTIMPL;
}

HRESULT UI::AddButton_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *Keys)
{
	try
	{
		if (ID->size() != Text->size() && Y->size() != Keys->size())
		{
			DebugTrace("UI: AddButton_Massive failed. An equal number of ID elements and text is required. Line: 63\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjButton.push_back(ID->at(i));
			ObjNameButton.push_back(Text->at(i));
			Dial->AddButton(ID->at(i), Text->at(i).c_str(), 35, Y->at(i), 125, 22, Keys->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddButton_Massive failed. Line: 76\n");
		throw std::exception("AddButton_Massive failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddButton_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y)
{
	try
	{
		if (ID->size() != Text->size())
		{
			DebugTrace("UI: AddButton_Massive failed. An equal number of ID elements and text is required. Line: 89\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjButton.push_back(ID->at(i));
			ObjNameButton.push_back(Text->at(i));
			Dial->AddButton(ID->at(i), Text->at(i).c_str(), 35, Y->at(i), 125, 22);
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddButton_Massive failed. Line: 102\n");
		throw std::exception("AddButton_Massive failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddStatic_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H)
{
	try
	{
		if (ID->size() != Text->size() && Y->size() != X->size())
		{
			DebugTrace("UI: AddStatic_Massive failed. An equal number of ID elements and text and X\Y is required. Line: 115\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjStatic.push_back(ID->at(i));
			ObjNameStatic.push_back(Text->at(i));
			Dial->AddStatic(ID->at(i), Text->at(i).c_str(), X->at(i), Y->at(i), W->at(i), H->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddStatic_Massive failed. Line: 128\n");
		throw std::exception("AddStatic_Massive failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddStatic(CDXUTDialog *Dial, int ID, wstring Text, int X, int Y, int W, int H)
{
	return E_NOTIMPL;
}

HRESULT UI::AddStatic(CDXUTDialog *Dial, int ID, wstring Text)
{
	try
	{
		//if (ID.size() != Text.size())
		//{
		//	DebugTrace("UI: AddStatic failed. An equal number of ID elements and text is required. Line: 67\n");
		//	throw std::exception("ID.size() != Text.size()!!!");
		//	return E_FAIL;
		//}
		ObjStatic.push_back(ID);
		ObjNameStatic.push_back(Text);
		Dial->AddStatic(ObjStatic.back(), ObjNameStatic.back().c_str(), 35, 90, 60, 50);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddStatic failed. Line: 156\n");
		throw std::exception("AddStatic failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

void UI::SetLocationButton(CDXUTDialog *Dial, int ID, int X, int Y)
{
	Dial->GetButton(ObjButton.at(ID))->SetLocation(X, Y);
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text)
{
	Dial->GetButton(ObjButton.at(ID))->SetText(Text->c_str());
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text, float Format[3])
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
			 Format[1], Format[2], Format[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, string *Text, float Format[3])
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
			 Format[1], Format[2], Format[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text, XMMATRIX Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
			 Format.r[4].m128_f32[1], Format.r[4].m128_f32[2], Format.r[4].m128_f32[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, string *Text, XMMATRIX Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
			 Format.r[4].m128_f32[1], Format.r[4].m128_f32[2], Format.r[4].m128_f32[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text, float Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"%.2f")).c_str()), Format);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, string *Text, float Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("%.2f")).c_str(), Format);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text, vector<size_t> Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(Text->c_str()), Format.data());
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, string *Text, vector<size_t> Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), Text->c_str(), Format.data());
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, wstring *Text, XMVECTOR Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
			 Format.m128_f32[1], Format.m128_f32[2], Format.m128_f32[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetTextButton(CDXUTDialog *Dial, int ID, string *Text, XMVECTOR Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
			 Format.m128_f32[1], Format.m128_f32[2], Format.m128_f32[3]);
	Dial->GetButton(ObjButton.at(ID))->SetText(A2W(buff));
	ZeroMemory(buff, sizeof(buff));
}

void UI::SetLocationStatic(CDXUTDialog *Dial, int ID, int X, int Y)
{
	Dial->GetStatic(ObjStatic.at(ID))->SetLocation(X, Y);
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text)
{
	Dial->GetStatic(ObjStatic.at(ID))->SetText(Text->c_str());
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text, float Format[3])
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
		Format[1], Format[2], Format[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, string *Text, float Format[3])
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
		Format[1], Format[2], Format[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text, XMMATRIX Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
		Format.r[4].m128_f32[1], Format.r[4].m128_f32[2], Format.r[4].m128_f32[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, string *Text, XMMATRIX Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
		Format.r[4].m128_f32[1], Format.r[4].m128_f32[2], Format.r[4].m128_f32[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text, float Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"%.2f")).c_str()), Format);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, string *Text, float Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("%.2f")).c_str(), Format);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text, vector<size_t> Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), 
	W2A(wstring(*Text + wstring(L"%Iu; Instances %Iu; Voices %Iu / %Iu / %Iu / %Iu;")).c_str()),
		Format.at(0), Format.at(1), Format.at(2),
		Format.at(3), Format.at(4), Format.at(5), Format.at(6));
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, string *Text, vector<size_t> Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), 
	string(*Text + string("%Iu; Instances %Iu; Voices %Iu / %Iu / %Iu / %Iu;")).c_str(), 
		Format.at(0), Format.at(1), Format.at(2),
		Format.at(3), Format.at(4), Format.at(5), Format.at(6));
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, wstring *Text, XMVECTOR Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), W2A(wstring(*Text + wstring(L"X:%.1f, Y:%.1f, Z:%.1f")).c_str()),
		Format.m128_f32[1], Format.m128_f32[2], Format.m128_f32[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

void UI::SetTextStatic(CDXUTDialog *Dial, int ID, string *Text, XMVECTOR Format)
{
	char buff[FILENAME_MAX];
	USES_CONVERSION;
	snprintf(buff, sizeof(buff), string(*Text + string("X:%.1f, Y:%.1f, Z:%.1f")).c_str(),
		Format.m128_f32[1], Format.m128_f32[2], Format.m128_f32[3]);
	Dial->GetStatic(ObjStatic.at(ID))->SetText(A2W(buff));
}

int UI::getAllComponentsCount() 
{
	vector<int> cache;
	for (int i = 0; i < ObjButton.size(); i++)
		cache.push_back(ObjButton.at(i));

	for (int i = 0; i < ObjStatic.size(); i++)
		cache.push_back(ObjStatic.at(i));

	for (int i = 0; i < ObjCheckBox.size(); i++)
		cache.push_back(ObjCheckBox.at(i));

	for (int i = 0; i < ObjSlider.size(); i++)
		cache.push_back(ObjSlider.at(i));

	for (int i = 0; i < ObjComboBox.size(); i++)
		cache.push_back(ObjComboBox.at(i));

	return cache.size();
}

vector<int> *UI::addToBackComponentBy_ID(int ID)
{
	vector<int> cache;
	cache.push_back(getAllComponentsCount() + ID);
	return &cache;
}

HRESULT UI::AddSlider(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H, int Min, int Max)
{
	try
	{
		ObjSlider.push_back(ID);
		ObjNameSlider.push_back(*Text);
		Dial->AddSlider(ObjSlider.back(), X, Y, W, H, Min, Max);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddSlider failed. Line: 409\n");
		throw std::exception("AddSlider failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddSlider_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H, vector<int> *Min, vector<int> *Max, vector<int> *DefValue)
{	
	try
	{
		for (int i = 0; i < ID->size(); i++)
		{
			ObjSlider.push_back(ID->at(i));
			ObjNameSlider.push_back(Text->at(i));

			Dial->AddSlider(ObjSlider.back(), X->at(i), Y->at(i), W->at(i), H->at(i), Min->at(i), 
							Max->at(i), DefValue->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddSlider_Mass failed. Line: 431\n");
		throw std::exception("AddSlider_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H, int Checked, int HotKey)
{
	try
	{
		ObjCheckBox.push_back(ID);
		ObjNameCheckBox.push_back(Text->c_str());
		Dial->AddCheckBox(ID, ObjNameCheckBox.back().c_str(), X, Y, W, H, Checked, HotKey);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox failed. Line: 445\n");
		throw std::exception("AddCheckBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H, vector<int> *Checked, vector<int> *HotKey)
{
	try
	{
		if (ID->size() != Text->size() && Y->size() != X->size())
		{
			DebugTrace("UI: AddCheckBox_Massive failed. An equal number of ID elements and text and X\Y is required. Line: 458\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjCheckBox.push_back(ID->at(i));
			ObjNameCheckBox.push_back(Text->at(i));
			Dial->AddCheckBox(ID->at(i), Text->at(i).c_str(), X->at(i), Y->at(i), W->at(i),
				H->at(i), Checked->at(i), HotKey->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox_Mass failed. Line: 472\n");
		throw std::exception("AddCheckBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H, int Checked)
{
	try
	{
		ObjCheckBox.push_back(ID);
		ObjNameCheckBox.push_back(Text->c_str());
		Dial->AddCheckBox(ID, ObjNameCheckBox.back().c_str(), X, Y, W, H, Checked);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox failed. Line: 489\n");
		throw std::exception("AddCheckBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H, vector<int> *Checked)
{
	try
	{
		if (ID->size() != Text->size() && Y->size() != X->size())
		{
			DebugTrace("UI: AddCheckBox_Massive failed. An equal number of ID elements and text and X\Y is required. Line: 502\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjCheckBox.push_back(ID->at(i));
			ObjNameCheckBox.push_back(Text->at(i));
			Dial->AddCheckBox(ID->at(i), Text->at(i).c_str(), X->at(i), Y->at(i), W->at(i),
				H->at(i), Checked->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox_Mass failed. Line: 516\n");
		throw std::exception("AddCheckBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H)
{
	try
	{
		ObjCheckBox.push_back(ID);
		ObjNameCheckBox.push_back(Text->c_str());
		Dial->AddCheckBox(ID, ObjNameCheckBox.back().c_str(), X, Y, W, H);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox failed. Line: 533\n");
		throw std::exception("AddCheckBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddCheckBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H)
{
	try
	{
		if (ID->size() != Text->size() && Y->size() != X->size())
		{
			DebugTrace("UI: AddCheckBox_Massive failed. An equal number of ID elements and text and X\Y is required. Line: 546\n");
			throw std::exception("ID.size() != Text.size()!!!");
			return E_FAIL;
		}
		for (int i = 0; i < ID->size(); i++)
		{
			ObjCheckBox.push_back(ID->at(i));
			ObjNameCheckBox.push_back(Text->at(i));
			Dial->AddCheckBox(ID->at(i), Text->at(i).c_str(), X->at(i), Y->at(i), W->at(i),
				H->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddCheckBox_Mass failed. Line: 560\n");
		throw std::exception("AddCheckBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H, int Checked, int HotKey)
{
	try
	{
		ObjComboBox.push_back(ID);
		ObjNameComboBox.push_back(*Text);
		Dial->AddComboBox(ID, X, Y, W, H, Checked, HotKey);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox failed. Line: 576\n");
		throw std::exception("AddComboBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H, vector<int> *Checked, vector<int> *HotKey)
{
	try
	{
		for (int i = 0; i < ID->size(); i++)
		{
			ObjComboBox.push_back(ID->at(i));
			ObjNameComboBox.push_back(Text->at(i));
			Dial->AddComboBox(ID->at(i), X->at(i), Y->at(i), W->at(i),
				H->at(i), Checked->at(i), HotKey->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox_Mass failed. Line: 601\n");
		throw std::exception("AddComboBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H, int Checked)
{
	try
	{
		ObjComboBox.push_back(ID);
		ObjNameComboBox.push_back(*Text);
		Dial->AddComboBox(ID, X, Y, W, H, Checked);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox failed. Line: 612\n");
		throw std::exception("AddComboBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H, vector<int> *Checked)
{
	try
	{
		for (int i = 0; i < ID->size(); i++)
		{
			ObjComboBox.push_back(ID->at(i));
			ObjNameComboBox.push_back(Text->at(i));
			Dial->AddComboBox(ID->at(i), X->at(i), Y->at(i), W->at(i),
				H->at(i), Checked->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox_Mass failed. Line: 632\n");
		throw std::exception("AddComboBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox(CDXUTDialog *Dial, int ID, wstring *Text, int X, int Y, int W, int H)
{
	try
	{
		ObjComboBox.push_back(ID);
		ObjNameComboBox.push_back(*Text);
		Dial->AddComboBox(ID, X, Y, W, H);
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox failed. Line: 648\n");
		throw std::exception("AddComboBox failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT UI::AddComboBox_Mass(CDXUTDialog *Dial, vector<int> *ID, vector<wstring> *Text, vector<int> *X, vector<int> *Y, vector<int> *W, vector<int> *H)
{
	try
	{
		for (int i = 0; i < ID->size(); i++)
		{
			ObjComboBox.push_back(ID->at(i));
			ObjNameComboBox.push_back(Text->at(i));

			Dial->AddComboBox(ID->at(i), X->at(i), Y->at(i), W->at(i),
				H->at(i));
		}
	}
	catch (const std::exception&)
	{
		DebugTrace("UI: AddComboBox_Mass failed. Line: 668\n");
		throw std::exception("AddComboBox_Mass failed!!!");
		return E_FAIL;
	}
	return S_OK;
}

int UI::getComponentBy_ID(UI *ui, int ID)
{
	vector<int> cache;
	for (int i1 = 0; i1 < ui->getAllComponentsCount(); i1++)
	{
		if (ID == i1)
		{
			cache.push_back(i1);
			for (int i = 0; i < ui->getDialogResManager()->m_Dialogs.size(); i++)
			{
				if (ui->getDialogResManager()->m_Dialogs.at(i)->GetCheckBox(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetButton(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetComboBox(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetSlider(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetStatic(i1))
					return cache[0];
			}
		}
	}
}

int UI::getComponentBy_ID(UI *ui, vector<int> *Obj, int ID)
{
	vector<int> cache;
	for (int i1 = 0; i1 < Obj->size(); i1++)
	{
		if (ID == i1)
		{
			cache.push_back(i1);
			for (int i = 0; i < ui->getDialogResManager()->m_Dialogs.size(); i++)
			{
				if (ui->getDialogResManager()->m_Dialogs.at(i)->GetCheckBox(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetButton(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetComboBox(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetSlider(i1))
					return cache[0];

				else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetStatic(i1))
					return cache[0];
			}
		}
	}
}

wstring UI::getComponentName_By_ID(UI *ui, int ID)
{
	for (int i = 0; i < ui->getDialogResManager()->m_Dialogs.size(); i++)
	{
		if (ui->getDialogResManager()->m_Dialogs.at(i)->GetCheckBox(ID))
			for (int i = 0; i < ui->getObjCheckBox()->size(); i++)
				 return ui->getObjNameCheckBox()->at(i);

		else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetButton(ID))
			for (int i = 0; i < ui->getObjButton()->size(); i++)
				 return ui->getObjNameButton()->at(i);

		else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetComboBox(ID))
			for (int i = 0; i < ui->getObjComboBox()->size(); i++)
				 return ui->getObjNameComboBox()->at(i);

		else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetSlider(ID))
			for (int i = 0; i < ui->getObjSlider()->size(); i++)
				 return ui->getObjNameSlider()->at(i);

		else if (ui->getDialogResManager()->m_Dialogs.at(i)->GetStatic(ID))
			for (int i = 0; i < ui->getObjStatic()->size(); i++)
				 return ui->getObjNameStatic()->at(i);
	}
	return L"";
}