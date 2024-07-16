#pragma once

enum SCENE { 
	TITLE, //タイトル
	STAGE, //ゲームシーン
	CLEAR //クリア
};

class IScene {
protected: 

	static int sceneNo;
public: 
  
	virtual void Init();
	virtual void Update(char* keys, char* preKeys);
	virtual void Draw();

	virtual ~IScene();

	int GetSceneNo();
};
