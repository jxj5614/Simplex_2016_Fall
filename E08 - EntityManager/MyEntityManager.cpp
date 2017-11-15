#include "MyEntityManager.h"
using namespace Simplex;
//  MyEntityManager
MyEntityManager* MyEntityManager::m_pInstance = nullptr;


void MyEntityManager::Init(void)
{
	entityID = std::vector<String>();
	m_entityList = std::vector<MyEntity*>();

}
void MyEntityManager::Release(void)
{
	for (int i = 0; i < m_entityList.size(); i++){
		delete m_entityList[i];
	}
}
MyEntityManager* MyEntityManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new MyEntityManager();
	}
	return m_pInstance;
}
void MyEntityManager::ReleaseInstance()
{

	if (m_pInstance != nullptr) {
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
int Simplex::MyEntityManager::GetEntityIndex(String a_sUniqueID)
{
	int index = -1;
	for (int i = 0; i < entityID.size(); i++) {
		if (entityID[i] == a_sUniqueID)
			index = i;
	}
	return index;
}
//Accessors
Model* Simplex::MyEntityManager::GetModel(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetModel();;
}
Model* Simplex::MyEntityManager::GetModel(String a_sUniqueID)
{
	if (GetEntityIndex(a_sUniqueID) != -1)
		return m_entityList[GetEntityIndex(a_sUniqueID)]->GetModel();

	return nullptr;
}
RigidBody* Simplex::MyEntityManager::GetRigidBody(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetRigidBody();
}
RigidBody* Simplex::MyEntityManager::GetRigidBody(String a_sUniqueID)
{
	if (GetEntityIndex(a_sUniqueID) != -1)
		return m_entityList[GetEntityIndex(a_sUniqueID)]->GetRigidBody();
}
matrix4 Simplex::MyEntityManager::GetModelMatrix(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetModelMatrix();
}
matrix4 Simplex::MyEntityManager::GetModelMatrix(String a_sUniqueID)
{

	if (GetEntityIndex(a_sUniqueID) != -1)
		return m_entityList[GetEntityIndex(a_sUniqueID)]->GetModelMatrix();
}
void Simplex::MyEntityManager::SetModelMatrix(matrix4 a_m4ToWorld, String a_sUniqueID)
{
	if(GetEntityIndex(a_sUniqueID) != -1)

		if (GetEntityIndex(a_sUniqueID) != -1)
			return m_entityList[GetEntityIndex(a_sUniqueID)]->SetModelMatrix(a_m4ToWorld);
}
void Simplex::MyEntityManager::SetModelMatrix(matrix4 a_m4ToWorld, uint a_uIndex)
{
	m_entityList[a_uIndex]->SetModelMatrix(a_m4ToWorld);
}
//The big 3
MyEntityManager::MyEntityManager(){Init();}
MyEntityManager::MyEntityManager(MyEntityManager const& other){ }
MyEntityManager& MyEntityManager::operator=(MyEntityManager const& other) { return *this; }
MyEntityManager::~MyEntityManager(){Release();};
// other methods
void Simplex::MyEntityManager::Update(void)
{

}
void Simplex::MyEntityManager::AddEntity(String a_sFileName, String a_sUniqueID)
{
	MyEntity* newEntity = new MyEntity(a_sFileName, a_sUniqueID);
	m_entityList.push_back(newEntity);
	entityID.push_back(a_sUniqueID);
}
void Simplex::MyEntityManager::RemoveEntity(uint a_uIndex)
{
	m_entityList.erase(m_entityList.begin() + a_uIndex);
}
void Simplex::MyEntityManager::RemoveEntity(String a_sUniqueID)
{
	if (GetEntityIndex(a_sUniqueID) != -1)
		m_entityList.erase(m_entityList.begin() + GetEntityIndex(a_sUniqueID));
}
String Simplex::MyEntityManager::GetUniqueID(uint a_uIndex)
{
	return entityID[a_uIndex];
}
MyEntity* Simplex::MyEntityManager::GetEntity(uint a_uIndex)
{
	return m_entityList[a_uIndex];
}
void Simplex::MyEntityManager::AddEntityToRenderList(uint a_uIndex, bool a_bRigidBody)
{
	if (a_uIndex == -1) {
		for (int i = 0; i < m_entityList.size(); i++) {
			m_entityList[i]->AddToRenderList(a_bRigidBody);
		}
	}
	else {
		m_entityList[a_uIndex]->AddToRenderList(a_bRigidBody);
	}
}
void Simplex::MyEntityManager::AddEntityToRenderList(String a_sUniqueID, bool a_bRigidBody)
{
	if (GetEntityIndex(a_sUniqueID) != 1) {
		m_entityList[GetEntityIndex(a_sUniqueID)]->AddToRenderList(a_bRigidBody);
	}
}