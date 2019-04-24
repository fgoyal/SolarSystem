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
    double total_distance = 0;
    for (int i = 0; i < kNumCelestialBodies; i++) {
        
        // scale radius so each radius is closer to average
        double scaled_radius = (kAvgRadius + kDampeningScalerRadius * ((diameters[i] / 2) - kAvgRadius)) * kRadiusScaler;
        
        // scale distance so each distance is closer to average
        double scaled_distance = (kAvgDistance + kDampeningScalerDistance * (distance[i] - kAvgDistance)) * kDistanceScaler;
        
        // get total distance
        total_distance += scaled_distance;

        if (i == 0) {
            total_distance -=scaled_distance;
        }
        
        ofVec3f position(total_distance, 0, 0);
        cout << names[i] << ": " << total_distance << '\n';
        CelestialBody planet(names[i], scaled_radius, textures[i], position);
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
    for (int i = 0; i < kNumCelestialBodies; i++) {
        celestial_bodies[i].GetTexture().bind();
        celestial_bodies[i].GetObject().draw();
        celestial_bodies[i].GetTexture().unbind();
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
