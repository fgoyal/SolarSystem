#include "ofApp.h"
#include "CelestialBody.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    cam.tilt(-90);
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
//    ofTranslate(screenWidth/2, screenHeight/2);
    
    // draw the planets and stars
    
    cam.begin();
    for (int i = 0; i < kNumCelestialBodies; i++) {
        celestial_bodies[i].draw(show_names, animate_orbits);
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
        helpStream << "n: show planet names: " << (show_names ? "YES" : "NO") << endl;
        helpStream << "1: show planet radii: " << (show_radius ? "YES" : "NO") << endl;
        helpStream << "2: show planet distances: " << (show_distances ? "YES" : "NO") << endl;
        helpStream << "3: show planet orbital velocities: " << (show_speeds ? "YES" : "NO") << endl;
        helpStream << "4: show planet orbital periods: " << (show_periods ? "YES" : "NO") << endl;
        helpStream << "o: animate planet orbits: " << (animate_orbits ? "YES" : "NO") << endl;
        helpStream << "v: reset camera" << endl;
        helpStream << "f: toggle full screen";
    }
    
    ofDrawBitmapStringHighlight(helpStream.str(), kHelpPosition, kHelpPosition);
    
    int count = 0;
    if (show_radius) {
        DrawInformationBox(count, 'r');
        count++;
    }
    if (show_distances) {
        DrawInformationBox(count, 'd');
        count++;
    }
    if (show_speeds) {
        DrawInformationBox(count, 's');
        count++;
    }
    if (show_periods) {
        DrawInformationBox(count, 'p');
        count++;
    }
    
}

//--------------------------------------------------------------
void ofApp::DrawInformationBox(int count, char type) {
    stringstream helpStream;
    
    ofSetColor(255);
    switch (type) {
        case 'r': helpStream << "Planet Radii" << endl;
            break;
        case 'd': helpStream << "Planet Distances From Sun" << endl;
            break;
        case 's': helpStream << "Planet Orbital Speeds" << endl;
            break;
        case 'p': helpStream << "Planet Orbital Periods" << endl;
            break;
    }

    for (int i = 0; i < kNumCelestialBodies; i++) {
        helpStream << names[i] << ": ";
        switch (type) {
            case 'r': helpStream << (int) diameters[i] / 2 << " km" << endl;
                break;
            case 'd': helpStream << distance[i] << " * 10^6 km" << endl;
                break;
            case 's': helpStream << orbital_speed[i] << " km/s" << endl;
                break;
            case 'p': helpStream << orbital_period[i] << " days" << endl;
                break;
        }
    }
    
    ofDrawBitmapStringHighlight(helpStream.str(), kHelpPosition, kInfoPosition + count * kInfoLength);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key =='f') {
        ofToggleFullscreen();
    }
    if (key == 'n') {
        show_names = !show_names;
    }
    
    if (key == '1') {
        show_radius = !show_radius;
    }
    
    if (key == '2') {
        show_distances = !show_distances;
    }
    
    if (key == '3') {
        show_speeds = !show_speeds;
    }
    
    if (key == '4') {
        show_periods = !show_periods;
    }
    
    if (key == 'o') {
        animate_orbits = !animate_orbits;
    }
    
    if (key == 'v') {
        cam.reset();
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
