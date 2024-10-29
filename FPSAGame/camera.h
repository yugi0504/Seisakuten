#pragma once
#include"DxLib.h"

class Camera
{
private:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///　定数
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const float INIT_CAMERA_X    = 0.0f;          //カメラX座標
    const float INIT_CAMERA_Y    = 1.0f;          //カメラY座標
    const float INIT_CAMERA_Z    = 0.0f;          //カメラZ座標

    const float INIT_CHARACTOR_X = 0.0f;          //キャラクターX座標
    const float INIT_CHARACTOR_Y = 0.0f;          //キャラクターY座標
    const float INIT_CHARACTOR_Z = 0.0f;          //キャラクターZ座標

    const float INIT_SPIN        = 0.0f;           //スピン初期

    const int   INIT_MOUSE_X     = 1920 / 2;      //マウスX座標(画面中央)
    const int   INIT_MOUSE_Y     = 1080 / 2;      //マウスY座標(画面中央)
    
    const float GRAV_ACC         = 9.8 / 10;      //重量加速度

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///　変数
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    VECTOR CameraPos;       //カメラ位置
    VECTOR TargetPos;       //注視点

    float charaPosX;        //キャラX座標
    float charaPosY;        //キャラY座標
    float charaPosZ;        //キャラZ座標

    float targetPosX;       //注視点X座標
    float targetPosY;       //注視点Y座標
    float targetPosZ;       //注視点Z座標

    float cameraYaw;        //横回転
    float cameraPitch;      //縦回転

    int   mousePosX;        //マウス座標X
    int   mousePosY;        //マウス座標Y

    bool  onGround;         //地面にいるかどうか

public:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///　メソッド
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /// <summary>
    /// カメラの初期化
    /// </summary>
    void CameraInitialize();
    /// <summary>
    /// マウスの初期化
    /// </summary>
    void MouseInitialize();
    /// <summary>
    /// カメラの更新
    /// </summary>
    void CameraUpdate();
    /// <summary>
    /// 視点移動
    /// </summary>
    void CameraMovement();
    /// <summary>
    /// キャラクター移動
    /// </summary>
    void CharaMovement();
};