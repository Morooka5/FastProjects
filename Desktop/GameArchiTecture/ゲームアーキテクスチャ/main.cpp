#include <DxLib.h>
#include <array> //stlを配列で表す
#include <cassert>
#include <memory>//スマートポインタ
#include <sstream>//ストレームマニピュレータ
#include <iostream>
#include <iomanip>
#include <string>
#include "Debug.h"
//.gitnore リポジトリ　作り直す
//sln vcxproj cpp sln を出す パブリック　コラボレート

/*int main() {
	char cstr[] = "HelloWorld";
	cout << "" << cstr[6] << endl;
	cout << "" << 6[cstr] << endl;
	cout << "" << *(cstr + 6) << endl;
	int a[] = { 1,2,3,4,5 };
	return 6;
}*/

struct Vector2 {
	float x, y;
};
using Position2 = Vector2;
//using KeyboardData_t = std::KeyboardData_t;
using KeyboardData_t = std::array<char, 256>;

struct Rect {
	Position2 center;
	float w;
	float h;
	float Left()const {}
	float Top()const {}
	float Right()const {}
	float Bottom()const {}
	float W()const {}
	float H()const {}
};
void MoveByInput(KeyboardData_t keystate, Rect rcA)
{
	constexpr float speed = 4.0f;

	if (keystate[KEY_INPUT_UP]) {
		rcA.center.y -= speed;
	}
	if (keystate[KEY_INPUT_DOWN]) {
		rcA.center.y += speed;
	}
	if (keystate[KEY_INPUT_LEFT]) {
		rcA.center.x -= speed;
	}
	if (keystate[KEY_INPUT_RIGHT]) {
		rcA.center.x += speed;
	}
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("2016210_諸岡響");
	SetGraphMode(640, 480, 16);             //ゲームウィンドウのサイズと色モードを設定
	
	ChangeWindowMode(true);                 //ゲームウィンドウの表示方法（false:フルスクリーン）
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int graphH[6] = {};
	for (int i = 0; 1 < 6; i++) {
		std::wostringstream oss;
		oss << L"./Asset/Adventurer-1.5/Individual Sprites/adventurer-run-";
		oss << std::setw(2);
		oss << std::setfill(L'0');
		oss << i << ".png";

		//graphH[i] = LoadGraph(oss.str().c_str());
	}
	/*Rect rcA = { 100,100,75,75 };
	KeyboardData_t keystate;
	
	int a[18] = {};
	a[5]++;
	a[7]++;
	*/
	unsigned int frameNo = 0;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		
		//GetHitKeyStateAll(keystate.data());
		//MoveByInput(keystate, rcA);
		/*
		int a[1000] = {};
		a[9977] = 9977;
		a[0] = 1;
		int j = 0;

		for (int i = 0; i < 10000; ++i)
		{
			++j;
			assert(i != 9977);
		}
	    char keystate[256];
		*/

		//GetHitKeyStateAll(keystate);
		int num = 0;
		//DrawBox(rcA.Left(), rcA.Top(), rcA.Top(), rcA.Bottom(), 0xffffff, true);
		DrawRotaGraph(200, 200, 4.0f, 0.0f, graphH[frameNo / 10], true);//char out[64];
		//wsprintf(out, "L=%d , y=%d\n", rcA.center.x, rcA.center.y);
		//OutputDebugString(out);
		Debug::Out(16);
		//Debug::Out(3.14f);
		test++;
		/*std::ostringstream* oss;
		*oss << "x=" << rcA, center.x;
		*oss << " , x=" << rcA, center.y << std::endl;
		OutputDebugStringA(* oss.str().c_str());
		*/
		ScreenFlip();
		frameNo = (frameNo + 1) % 60;

	}
	DxLib_End();
	return 0;
}
//Vector2 v = {10,10};
//auto vv = rcA.center + v;
//Vector2 vvv = { rcA.center.x + v.x,rcA.center.y + v.y };
//test++;
