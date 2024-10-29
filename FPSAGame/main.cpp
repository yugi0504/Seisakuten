#include"DxLib.h"
#include"camera.h"
#include"Model.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if (DxLib_Init() < 0) { return -1; }

    Model model;
    Camera camera;

    //3D���f��������
    model.ModelInitialize();

    //�J����������
    camera.CameraInitialize();

    //�}�E�X������
    camera.MouseInitialize();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        model.ModelDisplay();

        camera.CameraMovement();

        camera.CharaMovement();

        camera.CameraUpdate();
    }


    DxLib_End();
}