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
	 currentSceneNo_ = prevSceneNo_;
	prevSceneNo_= sceneArr_[prevSceneNo_]->GetSceneNo();

	if (currentSceneNo_ != prevSceneNo_)
	{
		sceneArr_[prevSceneNo_]->Init();
	}

	sceneArr_[prevSceneNo_]->Update(keys, preKeys);
	sceneArr_[prevSceneNo_]->Draw();

	return 0;
}