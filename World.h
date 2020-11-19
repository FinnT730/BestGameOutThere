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
    struct Block blocks[100];
} chunk;


struct World {
    struct Chunk chunks[100000];
} world;


void generate(int x, int y) {
    struct Block block1;
    block1.x = 7;
    block1.y = -2;
    block1.z = 3;
    block.color = PURPLE;
    chunk.blocks[0] = block1;
}


#endif //UNTITLED9_WORLD_H
