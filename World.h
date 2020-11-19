//
// Created by Gebruiker on 11/19/2020.
//

#include "raylib.h"

#ifndef UNTITLED9_WORLD_H
#define UNTITLED9_WORLD_H


struct Block {
    float y;
    float x;
    float z;
    Color color;
} block;


struct Chunk {
    int x;
    int y;
    struct Block blocks[];
} chunk;


struct World {
    struct Chunk chunks[];
} world;


#endif //UNTITLED9_WORLD_H
