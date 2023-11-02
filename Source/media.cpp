#include "media.h"

Texture2D Media::hills;
Texture2D Media::sky;
Texture2D Media::car;
Texture2D Media::clouds;
Texture2D Media::lake;
Texture2D Media::pole;
Texture2D Media::title;
Texture2D Media::anim;

void Media::media_init()
{
    hills = LoadTexture("paralHills.png");
    sky = LoadTexture("paralsky.png");
    car = LoadTexture("paralCar.png");
    clouds = LoadTexture("paralCloud.png");
    lake = LoadTexture("paralLake.png");
    pole = LoadTexture("paralPole.png");
    title = LoadTexture("paralTitle.png");

    anim = LoadTexture("anim.png");
}

void Media::media_unload()
{
    UnloadTexture(hills);
    UnloadTexture(sky);
    UnloadTexture(car);
    UnloadTexture(clouds);
    UnloadTexture(lake);
    UnloadTexture(pole);
    UnloadTexture(title);

    UnloadTexture(anim);
}