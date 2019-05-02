//
//  CelestialBody.cpp
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#include <CelestialBody.h>
#include <math.h>

//--------------------------------------------------------------
CelestialBody::CelestialBody(const string _name, const double _scaled_radius, const string _image, const double _orbital_speed, const double _orbital_period, const double _inclination, const double _distance_from_sun) {
    name = _name;
    scaled_radius = _scaled_radius;
    image = _image;
    distance_from_sun = _distance_from_sun;
    orbital_speed = _orbital_speed;
    orbital_period = _orbital_period;
    inclination = _inclination;
    center = ofVec3f(0, 0, distance_from_sun);
    ofLoadImage(texture, image);
    planet_body.setRadius(scaled_radius);
    inclination_x = sin(inclination * 2 * PI / kAngles);
    inclination_y = cos(inclination * 2 * PI / kAngles);
    
}

//--------------------------------------------------------------
void CelestialBody::draw(bool show_labels, bool animate_orbits, bool show_orbits, bool show_inclination) {
    
    // set position of object
    planet_body.setPosition(GetPosition(animate_orbits, show_inclination));
    
    // draw planet with texture
    texture.bind();
    planet_body.draw();
    texture.unbind();
    
    if (show_labels) {
        ShowNames();
    }
    
    if (show_orbits) {
        DrawOrbit(animate_orbits, show_inclination);
    }
}

//--------------------------------------------------------------
ofVec3f CelestialBody::GetPosition(bool animate_orbits, bool show_inclination) {
    if (animate_orbits) {
        double time_per_degree = orbital_period / kAngles;

        if (time_per_degree != 0) {
            if (show_inclination) {
                rotation.makeRotate(ofGetFrameNum() / time_per_degree + kQuarter, inclination_x, inclination_y, 0);
            } else {
                rotation.makeRotate(ofGetFrameNum() / time_per_degree + kQuarter, 0, 1, 0);
            }
            
        }
        
        position = rotation * center;
        return position;
        
    } else {
        position = ofVec3f(distance_from_sun, 0, 0);
        return position;
    }
}

//--------------------------------------------------------------
void CelestialBody::ShowNames() {
    ofPushMatrix();
    ofDrawBitmapString(name, position);
    ofPopMatrix();
}

//--------------------------------------------------------------
void CelestialBody::SetupOrbit(bool animate_orbits, bool show_inclination) {
    ofVec3f center = ofVec3f(0, 0, distance_from_sun);
    
    orbit.setMode(OF_PRIMITIVE_LINE_STRIP);
    orbit.clear();
    
    ofQuaternion rot;
    
    for (int i = 0; i <= kAngles; i++) {
        if (animate_orbits && show_inclination) {
            rot.makeRotate(i, inclination_x, inclination_y, 0);
        } else {
            rot.makeRotate(i, 0, 1, 0);
        }
        orbit.addVertex(rot * center);
    }
}

//--------------------------------------------------------------
void CelestialBody::DrawOrbit(bool animate_orbits, bool show_inclination) {
    SetupOrbit(animate_orbits, show_inclination);
    ofSetColor(kWhite, kWhite, kWhite, kOpacity);
    orbit.draw();
    ofSetColor(kWhite);
}
