#include "GameManager.h"
using namespace std;

GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>() ;
	sceneArr_[STAGE] = std::make_unique<StageScene>() ;
	sceneArr_[CLEAR] = std::make_unique<ClearScene>() ;

	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run(char* keys, char* preKeys)
{
	 prevSceneNo_ = currentSceneNo_;
	currentSceneNo_= sceneArr_[currentSceneNo_]->GetSceneNo();

	if (currentSceneNo_ != prevSceneNo_)
	{
		sceneArr_[currentSceneNo_]->Init();
	}

	sceneArr_[currentSceneNo_]->Update(keys, preKeys);
	sceneArr_[currentSceneNo_]->Draw();

	return 0;
}