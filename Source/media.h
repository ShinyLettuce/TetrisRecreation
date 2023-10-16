#pragma once
#include "raylib.h"

struct Media {
	static Texture2D hills;
	static Texture2D sky;
	static Texture2D car;
	static Texture2D clouds;
	static Texture2D lake;
	static Texture2D pole;
	static Texture2D title;

	static void media_init();
};