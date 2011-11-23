/* San Angeles Observation OpenGL ES version example
 * Copyright 2004-2005 Jetro Lauha
 * All rights reserved.
 * Web: http://iki.fi/jetro/
 *
 * This source is free software; you can redistribute it and/or
 * modify it under the terms of EITHER:
 *   (1) The GNU Lesser General Public License as published by the Free
 *       Software Foundation; either version 2.1 of the License, or (at
 *       your option) any later version. The text of the GNU Lesser
 *       General Public License is included with this source in the
 *       file LICENSE-LGPL.txt.
 *   (2) The BSD-style license that is included with this source in
 *       the file LICENSE-BSD.txt.
 *
 * This source is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the files
 * LICENSE-LGPL.txt and LICENSE-BSD.txt for more details.
 *
 * $Id: demo.c,v 1.10 2005/02/08 20:54:39 tonic Exp $
 * $Revision: 1.10 $
 */

#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>

#include "importgl.h"

#include "app.h"
#include "shapes.h"
#include "cams.h"


// Total run length is 20 * camera track base unit length (see cams.h).
#define RUN_LENGTH  (20 * CAMTRACK_LEN)
#undef PI
#define PI 3.1415926535897932f
#define RANDOM_UINT_MAX 65535


static unsigned long sRandomSeed = 0;
static GLfloat* point;
static GLubyte* color;


// Called from the app framework.
void appInit()
{
    int a;
    int i, j;
    glDisable(GL_NORMALIZE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_FLAT);
 //glEnable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glDisable(GL_LIGHT1);
    //glDisable(GL_LIGHT2);
    //glDisable(GL_LIGHTING);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    point = (GLfloat*)malloc(320*240*2*sizeof(GLfloat));
    color = (GLubyte*)malloc(320*240*4*sizeof(GLubyte));
    for(i=0; i<320; i++)
        for(j=0; j<240 * 2; j+=2)
        {
            point[i*480 + j + 1] = ((GLfloat)(i*1.0-160.0))/427.0;
            point[i*480 + j] = ((GLfloat)(j * 0.5) - 120.0)/240.0;
        }
        
    for(i=0; i<320; i++)
        for(j=0; j<240 * 4; j+=4)
        {
            color[i*960 + j] = 127;
            color[i*960 + j + 1] = 127;
            color[i*960 + j + 2] = 127;
            color[i*960 + j + 3] = 0;
        }
        
}


// Called from the app framework.
void appDeinit()
{
}

// Called from the app framework.
/* The tick is current time in milliseconds, width and height
 * are the image dimensions to be rendered.
 */
void appRender(long tick, int width, int height)
{
const GLfloat squareVertices[] = {

        -1.0, 1.0,             // Top left
        -1.0, -1.0,          // Bottom left
        1.0, -1.0,            // Bottom right
        1.0, 1.0,        // Top right

    };

    glVertexPointer(2, GL_FLOAT, 0, point);
    glColor4f(100.0, 0.0, 0.0,100.0);
    
    //glColorPointer(4, GL_UNSIGNED_BYTE, 0, color);
    //glDisableClientState(GL_NORMAL_ARRAY);
    glDrawArrays(GL_POINTS, 0, 320*240);
          //          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB,
          //              GL_UNSIGNED_SHORT_5_6_5, point);


}
