#pragma once
#ifndef __MODELS_H__
#define __MODELS_H__
#include "pch.h"

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Physics.h"
#include "File_system.h"
#include "Mesh.h"

#include <WICTextureLoader.h>

class Models: public Physics, public File_system, public Mesh
{
public:
	bool Load(string Filename);

	void Draw();

	auto *GetMeshes() { return &Meshes; }

	void Close();
	Models() {}
	~Models(){}
private:
	ID3D11ShaderResourceView *texture;
	ID3D11Device *Device = nullptr;

	Assimp::Importer importer;
	const aiScene *pScene;

	vector<Mesh> Meshes;
	vector<Texture> Textures_loaded;
	string Textype;

	HWND hwnd;

	void processNode(aiNode *node, const aiScene *Scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *Scene);

	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName, const aiScene *Scene);
	string determineTextureType(const aiScene *Scene, aiMaterial *mat);
	int getTextureIndex(aiString *str);
	
	ID3D11ShaderResourceView *getTextureFromModel(const aiScene *Scene, int Textureindex);

	void GetD3DDevice() { Device = DXUTGetD3D11Device(); }

	void GetD3DHWND() { hwnd = DXUTGetHWND(); }
};
#endif // !__MODELS_H__
