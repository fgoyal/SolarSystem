//#include "ofApp.h"
//#include "CelestialBody.h"
//#include <vector>
//
////--------------------------------------------------------------
//void ofApp::setup(){
//    ofBackground(0)
//    ofDisableAlphaBlending();
//    ofEnableDepthTest();
//    light.enable();
//
//    light.setPosition(ofVec3f(100,100,200));
//    light.lookAt(ofVec3f(0,0,0));
//
//    ofDisableArbTex();
//    double total_distance = 0;
//    for (int i = 0; i < kNumCelestialBodies; i++) {
//
//        // scale radius so each radius is closer to average
//        double scaled_radius = (kAvgRadius + kDampeningScalerRadius * ((diameters[i] / 2) - kAvgRadius)) * kRadiusScaler;
//
//        // scale distance so each distance is closer to average
//        double scaled_distance = (kAvgDistance + kDampeningScalerDistance * (distance[i] - kAvgDistance)) * kDistanceScaler;
//
//        // get total distance
//        total_distance += scaled_distance;
//
//        if (i == 0) {
//            total_distance -=scaled_distance;
//        }
//
//        ofVec3f position(total_distance, 0, 0);
//        //cout << names[i] << ": " << total_distance << '\n';
//        CelestialBody planet(names[i], scaled_radius, textures[i], 0, position);
//        celestial_bodies.push_back(planet);
//    }
//
//}
//
////--------------------------------------------------------------
//void ofApp::update(){
//
//}
//
////--------------------------------------------------------------
//void ofApp::draw(){
//    float screenWidth = ofGetWidth();
//    float screenHeight = ofGetHeight();
//    float width = screenWidth * 0.15;
//    cam.begin();
//    for (int i = 0; i < kNumCelestialBodies; i++) {
//        celestial_bodies[i].GetTexture().bind();
//        celestial_bodies[i].GetObject().draw();
//        celestial_bodies[i].GetTexture().unbind();
//    }
//    cam.end();
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyReleased(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){
//
//}


#include "ofApp.h"
#include "CelestialBody.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();

    background.load("stars_background.png");

    double total_distance = 0;
    for (int i = 0; i < kNumCelestialBodies; i++) {

        // scale radius so each radius is closer to average
        double scaled_radius = (kAvgRadius + kDampeningScalerRadius * ((diameters[i] / 2) - kAvgRadius)) * kRadiusScaler;

        // scale distance so each distance is closer to average
        double scaled_distance = (kAvgDistance + kDampeningScalerDistance * (distance[i] - kAvgDistance)) * kDistanceScaler;

        // get total distance
        total_distance += scaled_distance;

        if (i == 0) {
            total_distance = 0;
        }

//        ofVec3f position(total_distance, 0, 0);
//        cout << names[i] << ": " << scaled_radius << '\n';
//        cout << names[i] << ": " << total_distance << '\n';
        
        CelestialBody planet(names[i], scaled_radius, diameters[i]/2, textures[i], orbital_speed[i], orbital_period[i], total_distance);
        celestial_bodies.push_back(planet);
        total_distance += scaled_radius;
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float screenWidth = ofGetWidth();
    float screenHeight = ofGetHeight();
    
    ofDisableDepthTest();
    background.draw(0, 0, screenWidth, screenHeight);
    
    ofPopMatrix();
    ofEnableDepthTest();
    
    // set center of screen to 0,0
    ofTranslate(screenWidth/2, screenHeight/2);
    
    // draw the planets and stars
    cam.begin();
    for (int i = 0; i < kNumCelestialBodies; i++) {
        celestial_bodies[i].draw(show_names, show_radius);
//        celestial_bodies[i].GetObject().setParent(celestial_bodies[0]);
    }
    cam.end();
    DrawHelp();
}

//--------------------------------------------------------------
// Draw help panel (TODO: use ofxGui)
void ofApp::DrawHelp() {
    stringstream helpStream;
    
    ofSetColor(255);
    
    helpStream << "h: " << (show_help ? "hide" : "show") << " help";
    
    if (show_help) {
        helpStream << endl;
        helpStream << "1: show planet names: " << (show_names ? "YES" : "NO") << endl;
        helpStream << "2: show planet radiuses: " << (show_radius ? "YES" : "NO") << endl;
//        helpStream << "c: cycle cameras: ";
//        switch (camIndex) {
//            case 0:
//                helpStream << "ofEasyCam";
//                break;
//
//            case 1:
//                helpStream << "ofxSphereCam";
//                break;
//
//            case 2:
//                helpStream << "freecam";
//                break;
//
//        };
//        helpStream << endl;
//        helpStream << "move cameras with mouse:" << endl
//        << "  - left button: rotate" << endl
//        << "  - middle or m: xy translate" << endl
//        << "  - right: z translate" << endl;
//        helpStream << "r: reset cam" << endl;
        helpStream << "f: toggle full screen";
    }
    
    ofDrawBitmapStringHighlight(helpStream.str(), -ofGetScreenWidth()/2 + 10, -ofGetScreenHeight()/2 + 10);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key =='f') {
        ofToggleFullscreen();
    }
    if (key == '1') {
        show_names = !show_names;
    }
    if (key == '2') {
        show_radius = !show_radius;
    }
    
    if (key == 'h') {
        show_help = !show_help;
    }
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
