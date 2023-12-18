
#include "MyScene.h"

MyScene::MyScene() : Scene()
{

}
MyScene::~MyScene()
{
  
}
void MyScene::update(float deltaTime) 
{

   Fill(0, 0, SWIDTH, SHEIGHT, 0x2588, 0);

    for ( y = 0; y < SHEIGHT / 2; y++)
    {
        for(x = 0; x < SWIDTH / 2; x++)
        {
            middlePoint = 0.5f;
            roadWidth = 0.6f;
            clipWidth = roadWidth * 0.15f;

            roadWidth *= 0.5f;

            leftGrass = ( middlePoint - roadWidth - clipWidth) * SWIDTH;
            leftCLip = (middlePoint - roadWidth) * SWIDTH;

            rightGrass = ( middlePoint + roadWidth + clipWidth) * SWIDTH;
            rightClip = (middlePoint + roadWidth) * SWIDTH;

            nRow = SHEIGHT / 2 + y;

           
            if(x >= 0 && x< leftGrass)
                Draw(x, nRow, PIXEL_SOLID, FG_GREEN);
            if(x >= leftGrass && x < leftCLip)
                Draw(x, nRow, PIXEL_SOLID, FG_RED);
            if(x >= leftCLip && x < rightClip)
                Draw(x, nRow, PIXEL_SOLID, FG_GREY);
            if(x >= rightClip && x < leftGrass)
                Draw(x, nRow, PIXEL_SOLID, FG_GREY);
            if(x >= rightGrass && x < SWIDTH)
                Draw(x, nRow, PIXEL_SOLID, FG_GREEN);

        }
    }
}



