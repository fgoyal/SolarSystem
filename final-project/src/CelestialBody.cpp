//
//  CelestialBody.cpp
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#include <CelestialBody.h>

CelestialBody::CelestialBody(const string _name, const double _scaled_radius, const double _real_radius, const string _image, const double _orbital_speed, const double _orbital_period, const double _distance_from_sun) {
    name = _name;
    scaled_radius = _scaled_radius;
    real_radius = _real_radius;
    image = _image;
    distance_from_sun = _distance_from_sun;
    orbital_speed = _orbital_speed;
    orbital_period = _orbital_period;
    center = ofVec3f(0, 0, distance_from_sun);
    ofLoadImage(texture, image);
    planet_body.setRadius(scaled_radius);
    
}

void CelestialBody::draw(bool show_labels, bool show_radiuses, bool animate_orbits) {
    // spin around axis
    planet_body.rotate(1, 0, 1.0, 0.0);
    

    planet_body.setPosition(GetPosition(animate_orbits));
    
    // draw planet with texture
    texture.bind();
    planet_body.draw();
    texture.unbind();
    
    if (show_labels) {
        ShowNames();
    }
    
    if (show_radiuses) {
        ShowRadiuses();
    }
}

ofVec3f CelestialBody::GetPosition(bool animate_orbits) {
    if (animate_orbits) {
        // orbit around sun
        double time_per_degree = orbital_period / kAngles;
        
        if (time_per_degree != 0) {
            rotation.makeRotate(ofGetFrameNum() / time_per_degree + 90, 0, 1, 0);
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
//    ofTranslate(position, scaled_radius + 15, 0);
    ofDrawBitmapString(name, 0, 0);
    ofPopMatrix();
}

void CelestialBody::ShowRadiuses() {
    ofPushMatrix();
//    ofTranslate(position, scaled_radius + 5, 0);
    int radius = (int) real_radius;
    std::string radius_string = "Radius: " + std::to_string(radius) + "km";
    ofDrawBitmapString(radius_string, 0, 0);
    ofPopMatrix();
}

//void CelestialBody::SetTexture(string set_image) {
//    texture.loadImage(set_image);
//}
//
//void CelestialBody::SetPosition(ofVec3f set_position) {
//    planet_body.setPosition(set_position);
//}
