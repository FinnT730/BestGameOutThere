//
// Created by Gebruiker on 11/19/2020.
//

#include "raylib.h"

#ifndef UNTITLED9_WORLD_H
#define UNTITLED9_WORLD_H


//struct Block {
//    float y;
//    float x;
//    float z;
//    Color color;
//} block;
//
//
//struct Chunk {
//    int x;
//    int y;
//    struct Block blocks[100];
//} chunk;
//
//
//struct World {
//    struct Chunk chunks[100000];
//} world;
//
//int index = 0;
//
//void generate(int x, int y) {
//    Block block1{};
//    block1.x = 7;
//    block1.y = -1;
//    block1.z = 3;
//    block.color = PURPLE;
//    chunk.blocks[index] = block1;
//    index++;
//
//
//    for(int i = 0; i < 10; i++) {
//        Block block1{};
//        block1.x = i;
//        block1.y = -1;
//        block1.z = 3;
//        block.color = PURPLE;
//        chunk.blocks[index] = block1;
//        index++;
//    }
//
//}


class Block {
public:
    Block() {

    }

    float x,y,z;
    Color color;

    Block(float xo, float yo, float zo,Color color) {
        x = xo;
        y = yo;
        z = zo;
        this->color = color;
    }

};


class World {


private:
    int index = 0;

public:

    Block blocks[1024] = {Block(0,0,0,RED)};





    void generate(int x, int y) {
//        Block block { 3 , 0, 0, BROWN};
//        blocks[index] = block;
//        index++;

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < i + 4; j++) {
                Block block { static_cast<float>(x + i) , 0, static_cast<float>(y + j), BROWN};
                blocks[index] = block;
                index++;
            }
        }
    }


    World() : blocks() {

    }
};


#endif //UNTITLED9_WORLD_H
