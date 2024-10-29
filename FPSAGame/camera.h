#pragma once
#include"DxLib.h"

class Camera
{
private:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///�@�萔
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const float INIT_CAMERA_X    = 0.0f;          //�J����X���W
    const float INIT_CAMERA_Y    = 1.0f;          //�J����Y���W
    const float INIT_CAMERA_Z    = 0.0f;          //�J����Z���W

    const float INIT_CHARACTOR_X = 0.0f;          //�L�����N�^�[X���W
    const float INIT_CHARACTOR_Y = 0.0f;          //�L�����N�^�[Y���W
    const float INIT_CHARACTOR_Z = 0.0f;          //�L�����N�^�[Z���W

    const float INIT_SPIN        = 0.0f;           //�X�s������

    const int   INIT_MOUSE_X     = 1920 / 2;      //�}�E�XX���W(��ʒ���)
    const int   INIT_MOUSE_Y     = 1080 / 2;      //�}�E�XY���W(��ʒ���)
    
    const float GRAV_ACC         = 9.8 / 10;      //�d�ʉ����x

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///�@�ϐ�
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    VECTOR CameraPos;       //�J�����ʒu
    VECTOR TargetPos;       //�����_

    float charaPosX;        //�L����X���W
    float charaPosY;        //�L����Y���W
    float charaPosZ;        //�L����Z���W

    float targetPosX;       //�����_X���W
    float targetPosY;       //�����_Y���W
    float targetPosZ;       //�����_Z���W

    float cameraYaw;        //����]
    float cameraPitch;      //�c��]

    int   mousePosX;        //�}�E�X���WX
    int   mousePosY;        //�}�E�X���WY

    bool  onGround;         //�n�ʂɂ��邩�ǂ���

public:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///�@���\�b�h
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /// <summary>
    /// �J�����̏�����
    /// </summary>
    void CameraInitialize();
    /// <summary>
    /// �}�E�X�̏�����
    /// </summary>
    void MouseInitialize();
    /// <summary>
    /// �J�����̍X�V
    /// </summary>
    void CameraUpdate();
    /// <summary>
    /// ���_�ړ�
    /// </summary>
    void CameraMovement();
    /// <summary>
    /// �L�����N�^�[�ړ�
    /// </summary>
    void CharaMovement();
};