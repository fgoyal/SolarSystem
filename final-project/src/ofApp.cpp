#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableAlphaBlending();
    ofEnableDepthTest();
//    light.enable();
//    light.setPosition(ofVec3f(100,100,200));
//    light.lookAt(ofVec3f(0,0,0));
    
    ofDisableArbTex();
//    ofLoadImage(mTexSun,textures[0]);
//    ofLoadImage(mTexMercury,textures[1]);
//    ofLoadImage(mTexEarth,textures[3]);
//    mTexEarth.generateMipmap();
    //ofTexture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);
    
    float screenWidth = ofGetWidth();
    float screenHeight = ofGetHeight();
    float width = screenWidth * 0.15;
    earth.setPosition(-screenWidth * .5 + screenWidth *  3/4.f, screenHeight *  0.1/6.f, 0);
    
    sun.setRadius(width);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float screenWidth = ofGetWidth();
    float screenHeight = ofGetHeight();
    float width = screenWidth * 0.15;
    cam.begin();
    for (int i = 0; i < 10; i++) {
        earth.setPosition(-screenWidth * .5 + screenWidth *  3/4.f, screenHeight *  0.1/6.f, 0);
        
        sun.setRadius(width);
        ofLoadImage(mTex,textures[i]);
        mTex.bind();
        celestial_bodies[i].draw();
        mTex.unbind();
    }
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
