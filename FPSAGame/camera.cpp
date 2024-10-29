#include"camera.h"
#include<cmath>

void Camera::CameraInitialize()
{
    CameraPos = VGet(INIT_CAMERA_X, INIT_CAMERA_Y, INIT_CAMERA_Z);

    charaPosX = INIT_CHARACTOR_X;
    charaPosY = INIT_CHARACTOR_Y;
    charaPosZ = INIT_CHARACTOR_Z;

    cameraPitch = INIT_SPIN;
    cameraYaw   = INIT_SPIN;
}

void Camera::MouseInitialize()
{
    //マウスポインタの設定
    GetMousePoint(&mousePosX, &mousePosY);
    //マウスポインタ位置を画面中央に
    SetMousePoint(INIT_MOUSE_X, INIT_MOUSE_Y);
}

void Camera::CameraMovement()
{
    //マウス操作に応じて視点を更新
    cameraPitch -= (mousePosY - INIT_MOUSE_Y) * 0.01f;
    cameraYaw   += (mousePosX - INIT_MOUSE_X) * 0.01f;

    //上下回転の制限
    if (cameraPitch >  DX_PI / 2)cameraPitch =  DX_PI / 2;
    if (cameraPitch < -DX_PI / 2)cameraPitch = -DX_PI / 2;

    //注視点の計算
    targetPosX = charaPosX + cos(cameraPitch) * cos(cameraYaw);
    targetPosY = charaPosY + sin(cameraYaw);
    targetPosZ = charaPosZ + sin(cameraPitch) * cos(cameraYaw);

    TargetPos = VGet(targetPosX, targetPosY, targetPosZ);
}

void Camera::CharaMovement()
{
    //左移動
    if (CheckHitKey(KEY_INPUT_A))
    {
        charaPosX -= 10.0f;
    }
    //前進
    if (CheckHitKey(KEY_INPUT_W))
    {
        charaPosZ += 10.0f;
    }
    //後退
    if (CheckHitKey(KEY_INPUT_S))
    {
        charaPosZ -= 10.0f;
    }
    //右移動
    if (CheckHitKey(KEY_INPUT_D))
    {
        charaPosX += 10.0f;
    }
    //ジャンプ
    if (CheckHitKey(KEY_INPUT_SPACE) && onGround)
    {
        charaPosY += 10.0f;
        onGround = false;
    }
    //地面についている
    if (charaPosY < 0.0f)
    {
        charaPosY = 0.0f;
        onGround = true;
    }
}

void Camera::CameraUpdate()
{
    CameraPos = VGet(charaPosX, charaPosY, charaPosZ);

    SetCameraPositionAndTargetAndUpVec
    (
        CameraPos,
        TargetPos,
        VGet(cos(cameraPitch) * sin(cameraYaw), sin(cameraPitch), cos(cameraPitch) * sin(cameraYaw))
    );
    
}
