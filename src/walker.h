//
//  walker.h
//  yearLongTest
//
//  Created by Kim Ash on 4/3/13.
//  Copyright (c) 2013 Kim Ash. All rights reserved.
//

#ifndef yearLongTest_walker_h
#define yearLongTest_walker_h
#include "ofMain.h"

class walker {
    ofVec2f pos;
    ofImage image;
    ofPolyline line;
    ofShader shader;
    
public:

    void setup(ofVec2f pos, ofImage image);
    void render();
    void walk();
};


#endif