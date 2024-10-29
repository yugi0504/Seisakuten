#include"Model.h"
#include"DxLib.h"

void Model::ModelInitialize()
{
    mv1Handle = MV1LoadModel(HANDLE_NAME);
    MV1SetPosition(mv1Handle, VGet(INIT_HANDLE_POS_X, INIT_HANDLE_POS_Y, INIT_HANDLE_POS_Z));
}

void Model::ModelDisplay()
{
    MV1DrawModel(mv1Handle);
}