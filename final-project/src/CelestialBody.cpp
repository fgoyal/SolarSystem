//
//  CelestialBody.cpp
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#include <CelestialBody.h>
#include <math.h>


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
    
}

void CelestialBody::draw(bool show_labels, bool animate_orbits) {
    
    // set position of object
    planet_body.setPosition(GetPosition(animate_orbits));
    
    // draw planet with texture
    texture.bind();
    planet_body.draw();
    texture.unbind();
    
    if (show_labels) {
        ShowNames();
    }
}

ofVec3f CelestialBody::GetPosition(bool animate_orbits) {
    if (animate_orbits) {
        double time_per_degree = orbital_period / kAngles;
        
        double x = sin(inclination * 2 * PI / kAngles);
        double y = cos(inclination * 2 * PI / kAngles);

        if (time_per_degree != 0) {
            rotation.makeRotate(ofGetFrameNum() / time_per_degree + kQuarter, x, y, 0);
        }
        
        position = rotation * center;
        return position;
        
    } else {
        position = ofVec3f(distance_from_sun, 0, 0);
        return position;
    }
    
}

void CelestialBody::ShowNames() {
    ofPushMatrix();
    ofDrawBitmapString(name, position);
    ofPopMatrix();
}
