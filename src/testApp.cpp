#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    if(!player.loadMovie("pendulum720.mov"))   {
        ofLogError("Video failed to load!");
    }
    else    {
        ofBackground(255);
        ofEnableAlphaBlending();
        //player.setLoopState(OF_LOOP_NONE);
        player.setVolume(0);
        //player.play();  //move this to draw()
        videoImg.allocate(player.getWidth(), player.getHeight(), player.getPixelsRef().getImageType());
    }
    panel.setup(1280,150);
    panel.addPanel("Day of the Year");
    panel.addSlider("Day", 1, 1, 365, true);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
    if (player.isFrameNew()) {
        for (int y = 0; y < player.getHeight(); y++) {
            for (int x = 0; x < player.getWidth(); x++) {
                ofColor playerPix = player.getPixelsRef().getColor(x, y);
                videoImg.getPixelsRef().setColor(x, y, playerPix);
            }
        }
        videoImg.reloadTexture();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    curSlice = panel.getValueI("Day");
    player.play();
    for (int i = 0; i < player.getWidth(); i++) {
        videoImg.drawSubsection(i, 160, player.getWidth()/365, player.getHeight(), curSlice*(player.getWidth()/365), 0);
    }
    
    line.setup(ofVec2f(player.getWidth()/2, player.getHeight()/2));
    line.walk();
    line.render();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}