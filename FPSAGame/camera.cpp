#include"camera.h"
#include"DxLib.h"

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
    //�}�E�X�|�C���^�̐ݒ�
    GetMousePoint(&mousePosX, &mousePosY);
    //�}�E�X�|�C���^�ʒu����ʒ�����
    SetMousePoint(INIT_MOUSE_X, INIT_MOUSE_Y);
}

void Camera::CameraMovement()
{
    //�}�E�X����ɉ����Ď��_���X�V
    cameraPitch -= (mousePosY - INIT_MOUSE_Y) * 0.01f;
    cameraYaw   += (mousePosX - INIT_MOUSE_X) * 0.01f;

    //�㉺��]�̐���
    if (cameraPitch >  DX_PI / 2)cameraPitch =  DX_PI / 2;
    if (cameraPitch < -DX_PI / 2)cameraPitch = -DX_PI / 2;
}

void Camera::CharaMovement()
{
    //���ړ�
    if (CheckHitKey(KEY_INPUT_A))
    {
        charaPosX -= 10.0f;
    }
    //�O�i
    if (CheckHitKey(KEY_INPUT_W))
    {
        charaPosZ += 10.0f;
    }
    //���
    if (CheckHitKey(KEY_INPUT_S))
    {
        charaPosZ -= 10.0f;
    }
    //�E�ړ�
    if (CheckHitKey(KEY_INPUT_D))
    {
        charaPosX += 10.0f;
    }
    if (CheckHitKey(KEY_INPUT_SPACE) && onGround)
    {
        charaPosY += 10.0f;
        onGround = false;
    }
}

void Camera::CameraUpdate()
{
    CameraPos = VGet(charaPosX, charaPosY, charaPosZ);
}
