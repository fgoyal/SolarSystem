#include "ofApp.h"
#include "CelestialBody.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofDisableAlphaBlending();
    ofEnableDepthTest();
//    light.enable();
//    light.setPosition(ofVec3f(100,100,200));
//    light.lookAt(ofVec3f(0,0,0));
    
    ofDisableArbTex();
    ofLoadImage(mTexSun,textures[0]);
    ofLoadImage(mTexEarth,textures[3]);
//    mTexEarth.generateMipmap();
    //ofTexture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);
    
    float screenWidth = ofGetWidth();
    float screenHeight = ofGetHeight();
    float width = screenWidth * 0.15;
//    earth.setPosition(screenWidth * 0.25, 0, 0);
//    -1024*.5 + 1024*
    //std::cout << screenWidth;
    sun.setRadius(diameters[0] / 2 * kRadiusScaler);
    earth.setRadius(diameters[9] / 2 * kRadiusScaler);
    sun.setPosition(distance_from_sun[0] * kDistanceScaler, 0, 0);
    earth.setPosition(distance_from_sun[9] * kDistanceScaler, 0, 0);
//    mercury.setRadius(diameters[5] / 2 * kRadiusScaler);
//    mercury.setPosition(distance_from_sun[5], 0, 0);
    std::cout << sun.getX();
    std::cout << sun.getY();
    std::cout << sun.getZ() << '\n';
    std::cout << earth.getX();
    std::cout << earth.getY();
    std::cout << earth.getZ() << '\n';
    std::cout << earth.getRadius();
    
    for (int i = 0; i < kNumCelestialBodies; i++) {
        ofVec3f position(distance_from_sun[i] * kDistanceScaler, 0, 0);
        CelestialBody planet(names[i], (diameters[i] / 2) * kRadiusScaler, textures[i], position);
        celestial_bodies.push_back(planet);
    }
                                 
    
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
//    mTexSun.bind();
//    sun.draw();
//    mTexSun.unbind();
//    mTexEarth.bind();
//    earth.draw();
//    mTexEarth.unbind();
    for (int i = 0; i < kNumCelestialBodies; i++) {
        celestial_bodies[i].GetTexture().bind();
        celestial_bodies[i].GetObject().draw();
        celestial_bodies[i].GetTexture().unbind();
    }
//    mercury.draw();
//    for (int i = 0; i < 10; i++) {
//        earth.setPosition(-screenWidth * .5 + screenWidth *  3/4.f, screenHeight *  0.1/6.f, 0);
//
//        sun.setRadius(width);
//        ofLoadImage(mTex,textures[i]);
//        mTex.bind();
//        celestial_bodies[i].draw();
//        mTex.unbind();
//    }
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
