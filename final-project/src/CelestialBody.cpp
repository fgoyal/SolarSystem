//
//  CelestialBody.cpp
//  final-project
//
//  Created by Fiza Goyal on 4/16/19.
//

#include <CelestialBody.h>

CelestialBody::CelestialBody(const string _name, const double _scaled_radius, const double _real_radius, const string _image, const double _rotation_period, const double _position, const ofQuaternion _rotation) {
    name = _name;
    scaled_radius = _scaled_radius;
    real_radius = _real_radius;
    image = _image;
    position = _position;
    rotation_period = _rotation_period;
    rotations = _rotation;
    
    ofLoadImage(texture, image);
    planet_body.setRadius(scaled_radius);
    planet_body.setPosition(_position, 0, 0);
    
}

void CelestialBody::draw(bool show_labels, bool show_radiuses) {
    // draw sphere with texture
//    planet_body.rotate(10, 1.0, 0.0, 0.0);
    planet_body.rotate(1, 0, 1.0, 0.0);
    rotations.makeRotate(ofGetFrameNum(), 0, 1, 0);
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

void CelestialBody::ShowNames() {
    ofPushMatrix();
    ofTranslate(position, scaled_radius + 15, 0);
    ofDrawBitmapString(name, 0, 0);
    ofPopMatrix();
}

void CelestialBody::ShowRadiuses() {
    ofPushMatrix();
    ofTranslate(position, scaled_radius + 5, 0);
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
