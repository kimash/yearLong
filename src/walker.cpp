//
//  walker.cpp
//  yearLongTest
//
//  Created by Kim Ash on 4/3/13.
//  Copyright (c) 2013 Kim Ash. All rights reserved.
//

#include <iostream>
#include "walker.h"
#include "ofMain.h"

void walker::setup(ofVec2f pos, ofImage image){
    shader.load("shader");
    this->pos = pos;
    //this->image = image;
}

void walker::render(){
    ofPushStyle();
    ofSetColor(255);
    ofSetLineWidth(10);
    line.addVertex(pos.x, pos.y);
//    ofColor lineColor = image.getPixelsRef().getColor(pos.x, pos.y).invert();
//    ofSetColor(lineColor);
    line.draw();
    shader.begin();
    shader.setUniformTexture("tex", image, 0);
    image.draw(0, 0);
    shader.end();
    ofPopStyle();
}

void walker::walk(){
    float vx = ofRandom(-1,1);
    float vy = ofRandom(-1,1);
    pos.x += vx*50;
    pos.y += vy*50;
    //cout << "pos.x " << pos.x << endl;
    //pos.x = ofClamp(pos.x, 0, float(ofGetWidth()));
    //pos.y = ofClamp(pos.y, 0, float(ofGetHeight()));
}