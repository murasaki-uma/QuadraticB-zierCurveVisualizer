#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(255);
    ofSetFrameRate(60);
    
    
    line = ofPath();
    easyCam.rotate(-15, 1.0, 0.0, 0.0);
    
    float harf_width  = ofGetWidth()/2;
    float harf_height = ofGetHeight()/2;
    
    gui.setup(); // most of the time you don't need a name
    gui.add(begin.setup("beginPos", ofVec3f(-200, 200,0), ofVec3f(-harf_width, -harf_height,-500), ofVec3f(harf_width, harf_height,500)));
    gui.add(end.setup("endPos", ofVec3f(200, 200, 0), ofVec3f(-harf_width, -harf_height,-500), ofVec3f(harf_width, harf_height,500)));
    gui.add(control.setup("controlPos", ofVec3f(0, 100, 0), ofVec3f(-harf_width, -harf_height,-500), ofVec3f(harf_width, harf_height,500)));
    gui.add(p.setup("p", 0.5, 0.0, 1.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    easyCam.begin();
    ofEnableDepthTest();
    
    ofSetColor(0);
    ofDrawGrid(500, 10, false, false, true, false);
    
    
    line.clear();
    line.setStrokeColor( ofColor(0) );
    line.setFilled(false);
    line.setStrokeWidth( 1 );
    
    line.quadBezierTo(begin, control, end);
    
    line.draw();
    line.close();
    
    
    
    
    
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0,0,200,200);
    
    ofDrawSphere(begin,4);
    ofDrawBitmapString("begin", ofVec3f(begin->x+5.0, begin->y-10.0, begin->z));
    ofDrawSphere(control,4);
    ofDrawBitmapString("control", ofVec3f(control->x+5.0, control->y-10.0, control->z));
    ofDrawSphere(end,4);
    ofDrawBitmapString("end", ofVec3f(end->x+5.0, end->y-10.0, end->z));
    
    
    ofVec3f interpolate_point = getBezierInterpolate_vec3f(p, begin, control, end);
    ofSetColor(200,0,0,200);
    ofDrawSphere(interpolate_point, 4);
    ofDrawBitmapString("interpolate", ofVec3f(interpolate_point.x+5.0, interpolate_point.y-10.0, interpolate_point.z));
    
    ofDrawLine(begin, control);
    ofDrawLine(end, control);
    
    ofDisableAlphaBlending();
    ofDisableDepthTest();
    
    easyCam.end();
    
    
    gui.draw();


    
    
    

}

ofVec2f ofApp::getBezierInterpolate_vec2f(float point, ofVec2f begin, ofVec2f control, ofVec2f end) {
    
        float tp = 1 - point;
        float x = point*point*end.x + 2*point*tp*control.x + tp*tp*begin.x;
        float y = point*point*end.y + 2*point*tp*control.y + tp*tp*begin.y;
        return ofVec2f(x,y);
    
}

ofVec3f ofApp::getBezierInterpolate_vec3f(float point, ofVec3f begin, ofVec3f control, ofVec3f end) {
    
    float tp = 1 - point;
    float x = point*point*end.x + 2*point*tp*control.x + tp*tp*begin.x;
    float y = point*point*end.y + 2*point*tp*control.y + tp*tp*begin.y;
    float z = point*point*end.z + 2*point*tp*control.z + tp*tp*begin.z;
    return ofVec3f(x,y,z);
    
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
