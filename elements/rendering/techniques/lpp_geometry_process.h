/*
The MIT License (MIT)
Copyright (c) 2016 Alexey Yegorov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

#ifndef RENDERING_MODELS_LPP_GEOMETRY_PROCESS_H_INCLUDED
#define RENDERING_MODELS_LPP_GEOMETRY_PROCESS_H_INCLUDED

#include "rendering/core/program.h"
#include "rendering/models/model.h"
#include "scene/scene.h"

namespace eps {
namespace rendering {

class lpp_geometry_process : public scene::visitor<lpp_geometry_process, scene::scene &>
{
public:

    EPS_DESIGN_VISIT(model);

public:

    bool initialize();
    void visit(const model & m, scene::scene & scene);

private:

    program program_;
};

} /* rendering */
} /* eps */

#endif // RENDERING_MODELS_PROCESS_LPP_GEOMETRY_H_INCLUDED
