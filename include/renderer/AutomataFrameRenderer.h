#pragma once
#include <vector>

#include "Renderer.h"
#include "Shader.h"
#include "core/Entity.h"

// TODO: figure out how to do this... a problem for later tho!
// this will be a fancy texture that i create per frame and send to the gpu (hopefully)
class AutomataFrameRenderer {
public:
    AutomataFrameRenderer();
    ~AutomataFrameRenderer();


    // void render();
    // void clear();

private:
    std::vector<Shader> shaders;
    std::vector<Entity> curr_frame_buffer;
    std::vector<Entity> next_frame_buffer;
};