#pragma once
#ifndef __GAME_OBJECTS_H__
#define __GAME_OBJECTS_H__
#include "pch.h"

class Models;
class SimpleLogic;
class Timer;
class GameObjects
{
public:
	enum TYPE { Model = 1, Sound_Obj, NONE };
	struct Object
	{
	private:
		//static int ID;

		TYPE type = (TYPE)NONE;

		// Use To Load File (e.g. file name of model)
		string ID_TEXT, ModelNameFile;

		Vector3 PosCoords = Vector3::Zero;

		const Vector3 ResetPos, ResetRot, ResetScl;
		
		bool HasScale = false;
		Vector3 ScaleCoords = Vector3::Zero;

		bool HasRotation = false;
		Vector3 RotationCoords = Vector3::Zero;
		
		float Test1 = 1.0f, Test2 = 1.5f;

		shared_ptr<Models> model;
		shared_ptr<SimpleLogic> Logic;
		//PxRigidDynamic *PH = nullptr;
		shared_ptr<Timer> time;
	public:
		Object() {}
		Object(string ID_TEXT, string ModelNameFile, shared_ptr<SimpleLogic> Logic,
			TYPE type, Vector3 PosCoords = Vector3::Zero, Vector3 ScaleCoords = Vector3::Zero,
			Vector3 RotationCoords = Vector3::Zero);

		void SetID_TEXT(LPCSTR _ID_TEXT) { ID_TEXT = _ID_TEXT; }

		void SetHasScale(bool _HasScale) { HasScale = _HasScale; }
		void SetScaleCoords(Vector3 _ScaleCoords) { ScaleCoords = _ScaleCoords; }

		void SetHasRotation(bool _HasRotation) { HasRotation = _HasRotation; }
		void SetRotationCoords(Vector3 _RotationCoords) { RotationCoords = _RotationCoords; }

		void SetPositionCoords(Vector3 _PosCoords) { PosCoords = _PosCoords; }

		void SetModel(shared_ptr<Models> Model) { model = Model; }
		void SetType(TYPE Type) { type = Type; }
		void SetLogic(shared_ptr<SimpleLogic> Logic);
		void RemoveLogic();
		//void SetPH(PxRigidDynamic *PH) { this->PH = PH; }

		//int GetID() { return ID; }
		auto GetType() { return type; }

		bool GetScale() { return HasScale; }
		bool GetRotation() { return HasRotation; }
		string GetIdText() { return ID_TEXT; }
		string GetModelNameFile() { return ModelNameFile; }

		Vector3 GetRotCord() { return RotationCoords; }
		Vector3 GetScaleCord() { return ScaleCoords; }
		Vector3 GetPositionCord() { return PosCoords; }
		
		// R means "Reset"
		Vector3 GetRRot() { return ResetRot; }
		// R means "Reset"
		Vector3 GetRScale() { return ResetScl; }
		// R means "Reset"
		Vector3 GetRPos() { return ResetPos; }

		shared_ptr<Models> GetModel() { return model; }
		shared_ptr<SimpleLogic> GetLogic() { return Logic; }
		//PxRigidDynamic *GetPH() { return PH; }

		void UpdateLogic(float Time);

		void Destroy();

		bool RenderIt = true;
	};

	//void Update();

	auto getObjects() { return Objects; }
	void setObject(shared_ptr<Object> Obj) { Objects.push_back(Obj); }
protected:
	//********
	HRESULT hr = S_OK;

	//********
	vector<shared_ptr<Object>> Objects;
};
#endif // !__GAME_OBJECTS_H__
